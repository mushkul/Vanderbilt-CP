import requests
from bs4 import BeautifulSoup
import sys


def getParagraphs(description_block, start_element, end_element):
    include = False
    paragraphs = []

    for element in description_block.children:
        if element == end_element:
            break
        if element == start_element:
            include = True
        if include and hasattr(element, 'text') and element.name not in ["h1", "h2", "h3", "h4", "h5", "h6"]:
            paragraphs.append(element)

    description = " ".join(paragraph.text for paragraph in paragraphs)

    return description


def getProblemInfo(url):
    response = requests.get(url)

    # Check if the request was successful
    if response.status_code == 200:
        # Parse the HTML content
        soup = BeautifulSoup(response.content, "html.parser")

        # Initialize variables
        title_block = soup.find(class_="title-block")
        description_block = soup.find(class_="md")
        category = soup.find(class_="nav sidebar").find("h4").text
        title = title_block.find("h1").text
        description_list = description_block.find_all("p")
        time_limit = ""
        memory_limit = ""
        input_specification = ""
        output_specification = ""
        constraints = ""
        example_input = ""
        example_output = ""

        # Extract time limit and memory limit
        constraints_list = soup.find_all("li")
        for constraint in constraints_list:
            if "Time limit:" in constraint.text:
                time_limit = constraint.text.replace("Time limit:", "").strip()
            elif "Memory limit:" in constraint.text:
                memory_limit = constraint.text.replace(
                    "Memory limit:", "").strip()

        # Extract input and output sections
        input_header = soup.find("h1", id="input")
        output_header = soup.find("h1", id="output")
        constraints_header = soup.find("h1", id="constraints")

        if input_header:
            input_specification = getParagraphs(
                description_block, input_header, output_header)
            # input_header.find_next_sibling("p").text

        if output_header:
            output_specification = getParagraphs(
                description_block, output_header, constraints_header)
            # output_header.find_next_sibling("p").text

        statement_paragraphs = []
        for element in description_block.children:
            if element == input_header:
                break
            if element.name == "p":
                statement_paragraphs.append(element)

        description = getParagraphs(
            description_block, soup.find("p"), input_header)

        # Extract constraints

        if constraints_header:
            constraints = constraints_header.find_next("ul")
            constraints = constraints.text if constraints is not None else ""

        # Extract example input and output
        example_header = soup.find("h1", id="example")
        if example_header:
            example_input = example_header.find_next("pre").text.strip()
            example_output = example_header.find_next(
                "pre").find_next("pre").text.strip()

        # Print or store the results
        problemInfo = {
            "Title": title,
            "Category": category,
            "Time Limit": time_limit,
            "Memory Limit": memory_limit,
            "Description": description,
            "Input Specification": input_specification,
            "Output Specification": output_specification,
            "Constraints": constraints.strip(),
            "Example Input": example_input,
            "Example Output": example_output
        }

        return problemInfo
    else:
        print(f"Failed to fetch the page. Status code: {response.status_code}")
        return {}


if __name__ == "__main__":
    print(getProblemInfo(sys.argv[1]))
