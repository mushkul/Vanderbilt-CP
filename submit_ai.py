from openai import OpenAI
import os
import json
import sys
from dotenv import load_dotenv
import subprocess
import anthropic


def get_prompt(problem_info: dict[str, str]):
    prompt = "Write only the C++ code solution to the following problem. Do not include any explanation, comments, or additional text. Only output the code to solve the following competitive programming problem:\n\n"

    spec_names = {"Title", "Time Limit", "Memory Limit"}
    specs = {key: problem_info[key]
             for key in spec_names if key in problem_info}

    for key, value in specs.items():
        prompt += key + ": " + value + "\n"

    for key, value in problem_info.items():
        if key != 'Number' and value != "Category" and key not in specs:
            prompt += key + ": " + value + "\n\n"

    return prompt


class LLM:
    def __init__(self, model):
        # self.api_key = api_key
        if model.lower().startswith("gpt"):
            self.client = OpenAI(
                # This is the default and can be omitted
                api_key=os.environ.get("OPENAI_API_KEY"),
                organization="org-sPGJK1LGE6NIDlI1jeU3VmY8",
            )
            self.type = "gpt"
        else:
            self.client = anthropic.Anthropic(
                # defaults to os.environ.get("ANTHROPIC_API_KEY")
                api_key=os.environ.get("ANTHROPIC_API_KEY"),
            )
            self.type = "anthropic"
        self.model = model

    def request(self, prompt):
        if self.type == "gpt":
            response = self.client.chat.completions.create(
                messages=[
                    {"role": "user", "content": prompt}
                ],
                model=self.model,
            )
            return response.choices[0].message.content.strip()
        else:
            response = self.client.messages.create(
                model=self.model,
                max_tokens=8192,
                messages=[
                    {"role": "user", "content": prompt}
                ]
            )
            return response.content[0].text.strip()


def solve_problem(problem_info: dict[str, str], model_name):
    prompt = get_prompt(problem_info)

    obj = LLM(model_name)
    response_text = obj.request(prompt)

    # client = OpenAI(
    #     # This is the default and can be omitted
    #     api_key=os.environ.get("OPENAI_API_KEY"),
    #     organization="org-sPGJK1LGE6NIDlI1jeU3VmY8",
    # )

    # response = client.chat.completions.create(
    #     messages=[
    #         {"role": "user", "content": prompt}
    #     ],
    #     model=model_name,
    # )

    # # Print the C++ solution
    # response_text = response.choices[0].message.content.strip()

    # Extract code and remove markers
    import re
    code_block = re.search(r"```(?:cpp)?(.*?)```", response_text, re.DOTALL)
    if code_block:
        cpp_code = code_block.group(1).strip()
    else:
        cpp_code = response_text  # Assume response is already clean

    # cpp_solution = response.choices[0].message.content
    # a = response.choices[0].message
    # breakpoint()

    return cpp_code


def main():
    load_dotenv()
    model_name = sys.argv[1]

    # OpenAI API key setup
    # Replace with your actual API key
    for filename in os.listdir(os.path.join(".", "problemset")):
        if not filename.endswith(".json"):
            continue
        with_cpp = filename.replace(".json", ".cpp")
        if os.path.exists(os.path.join(".", "solutions", model_name, with_cpp)):
            continue

        with open(os.path.join(".", "problemset", filename), "r") as f:
            problem_info = json.load(f)
            cpp_solution = solve_problem(problem_info, model_name)
            problem_id = filename.split(".")[0]
            subprocess.run(
                ["mkdir", "-p", os.path.join(".", "solutions", model_name)])
            with open(os.path.join(".", "solutions", model_name, problem_id + ".cpp"), 'w') as cpp_sol:
                cpp_sol.write(cpp_solution)
            # break

    # Problem details in JSON
    # problem_statement = {
    #     "Title": "Stick Lengths",
    #     "Category": "Sorting and Searching",
    #     "TimeLimit": "1.00 s",
    #     "MemoryLimit": "512 MB",
    #     "Description": "There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length. You can either lengthen or shorten each stick. Both operations cost x where x is the difference between the new and original length. What is the minimum total cost?",
    #     "InputSpecification": "The first input line contains an integer n: the number of sticks. Then there are n integers: p_1, p_2,...,p_n: the lengths of the sticks.",
    #     "OutputSpecification": "Print one integer: the minimum total cost.",
    #     "Constraints": "1 ≤ n ≤ 2 × 10⁵, 1 ≤ p_i ≤ 10⁹",
    #     "ExampleInput": "5\n2 3 1 5 2",
    #     "ExampleOutput": "5",
    #     "Number": 1074
    # }

    # Construct the prompt

    # API call


if __name__ == '__main__':
    main()

    # prompt = f"""
    # Write a C++ program to solve the following competitive programming problem:

    # Title: {problem_statement['Title']}
    # Category: {problem_statement['Category']}
    # Time Limit: {problem_statement['TimeLimit']}
    # Memory Limit: {problem_statement['MemoryLimit']}

    # Description:
    # {problem_statement['Description']}

    # Input Specification:
    # {problem_statement['InputSpecification']}

    # Output Specification:
    # {problem_statement['OutputSpecification']}

    # Constraints:
    # {problem_statement['Constraints']}

    # Example Input:
    # {problem_statement['ExampleInput']}

    # Example Output:
    # {problem_statement['ExampleOutput']}

    # Write an efficient and optimized solution in C++ that adheres to the constraints and input/output specifications.
    # """
