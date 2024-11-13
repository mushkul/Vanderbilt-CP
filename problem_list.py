"""
Script to get all problem links from cset problemset
"""

import requests
from bs4 import BeautifulSoup
import sys


def main():
    url = "https://www.cses.fi/problemset"
    response = requests.get(url)
    soup = BeautifulSoup(response.content, "html.parser")

    tasks = soup.find_all("li", class_="task")
    # print(links[3].)
    problem_links = []
    for task in tasks:
        name = task.find('a').text
        link = task.find('a')['href']
        problem_links.append(f"https://www.cses.fi{link}")
        print(f"https://www.cses.fi{link}")
    
    with open("problem_links.txt", "w") as f:
        for link in problem_links:
            f.write(link + "\n")

if __name__ == "__main__":
    main()