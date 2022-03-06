import sys
import json


def main(path):
    file = open(path, "r")
    input = json.loads(file.readline())
    file.close()
    with open("../inputs/parsed_input", 'x') as f:
        for item in input:
            f.write(str(item[0]) + " " + str(item[1]) + "\n")
    f.close()


if __name__ == '__main__':
    main(sys.argv[1])
