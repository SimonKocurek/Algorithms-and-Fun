from collections import namedtuple, deque
from typing import List

Meeting = namedtuple('Meeting', ['start', 'end'])


def meeting_rooms(meetings: List[Meeting]) -> int:
    meetings.sort(key=lambda x: x.end)

    result = 0
    using = deque()

    for meeting in meetings:
        using.append(meeting)

        while using[0].end <= meeting.start:
            using.popleft()

        result = max(result, len(using))

    return result


def main() -> None:
    print(meeting_rooms([Meeting(0, 30), Meeting(5, 10), Meeting(15, 20)]), 'Expected: 2')
    print(meeting_rooms([Meeting(0, 30), Meeting(5, 10), Meeting(15, 20), Meeting(1, 19)]), 'Expected: 3')
    print(meeting_rooms([Meeting(0, 30), Meeting(5, 10), Meeting(15, 20), Meeting(0, 20)]), 'Expected: 3')
    print(meeting_rooms([Meeting(0, 30), Meeting(5, 10), Meeting(15, 20), Meeting(9, 50)]), 'Expected: 3')
    print(meeting_rooms([]), 'Expected: 0')
    print(meeting_rooms([Meeting(0, 30)]), 'Expected: 1')
    print(meeting_rooms([Meeting(0, 30), Meeting(30, 50)]), 'Expected: 1')
    print(meeting_rooms([Meeting(0, 30), Meeting(35, 50)]), 'Expected: 1')


if __name__ == '__main__':
    main()
