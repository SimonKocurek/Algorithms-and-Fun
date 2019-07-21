def load_intervals():
    intervals = int(input())
    return [list(map(int, input().split())) for _ in range(intervals)]

def to_events(intervals):
    events = []

    for interval in intervals:
        start, end = interval
        events.append((start, 's'))
        events.append((end, 'e'))

    return events

def least_workers(intervals):
    events = to_events(intervals)
    # 's' < 'e' so in case 'start' and 'end' event happen at the same time, the start is counted to the max first
    # Because Python uses stable sorting, we can do this in 2 passes
    events.sort(key=lambda x: x[1])
    # sort events by their time
    events.sort()

    result = 0
    currently_working = 0

    for event in events:
        start, event_type = event

        if event_type == 's':
            currently_working += 1
        elif event_type == 'e':
            currently_working -= 1
        else:
            print(f'Invalid event type {event_type}')
            exit(-1)

        result = max(result, currently_working)

    return result

def main():
    intervals = load_intervals()
    result = least_workers(intervals)
    print(result)

main()
