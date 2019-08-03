from math import sqrt


def main():
    count = int(input())

    points = []
    for _ in range(count):
        points.append(list(map(int, input().split())))
    points.sort()
    points.insert(0, [points[0][0], 0])
    points.append([points[-1][0], 0])

    hull = []
    for point in points:
        if len(hull) >= 2 and wrong(hull[-2], hull[-1], point):
            hull.pop()
        hull.append(point)

    result = 0
    for i in range(1, len(hull)):
        result += sqrt((hull[i][0] - hull[i - 1][0]) ** 2 + (hull[i][1] - hull[i - 1][1]) ** 2)
    print(result)


def wrong(a, b, c):
    return (b[1] - a[1]) * (c[0] - b[0]) <= (c[1] - b[1]) * (b[0] - a[0])


main()
