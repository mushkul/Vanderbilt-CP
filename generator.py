from webscraper import getProblemInfo
import json
import os

if __name__ == '__main__':
    with open("problem_links.txt", 'r') as f:
        for line in f.readlines():
            line = line.rstrip()
            number = line.split('/')[-1]
            problemInfo = getProblemInfo(line)
            problemInfo["Number"] = int(number)
            output_file = os.path.join("problemset", f"{number}.json")
            with open(output_file, "w") as outfile:
                json.dump(problemInfo, outfile)
