import os
import glob
import sys
import subprocess


def main(model_name):
    directory_files = os.path.join(".", "solutions", model_name, "*.cpp")
    for filename in glob.glob(directory_files):
        with open(filename, "r") as f:
            with_json = filename.replace(".cpp", ".json")
            if not os.path.exists(with_json):
                subprocess.run(["node", "index.js", filename])


if __name__ == '__main__':
    main(sys.argv[1])
