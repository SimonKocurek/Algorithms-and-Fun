def main():
    all_names = set()
    all_children = set()

    line = input()
    while line != "":
        name, value, *children = line.split()

        all_names.add(name)
        for child in ''.join(children[1:]).split(','):
            all_children.add(child)

        line = input()

    print(all_names - all_children)


main()
