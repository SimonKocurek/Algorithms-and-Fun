# 5
# 2 2 30
# 4 6 90
# 8 10 90
# 12 12 30
# 5 9 250

from collections import namedtuple

Job = namedtuple('Job', ['start', 'end', 'compensation'])


def load_jobs():
    count = int(input())

    jobs = []
    for _ in range(count):
        start, end, compensation = map(int, input().split())
        jobs.append(Job(start, end, compensation))

    return jobs


def highest_profit(jobs: [Job]):
    jobs.sort(key=lambda job: job.end)
    last_day = jobs[-1].end

    profit_in_day = [0, 0]
    current_job = 0
    for day in range(last_day + 1):
        highest_possible_profit = profit_in_day[-1]

        while current_job < len(jobs) and jobs[current_job].end <= day:
            job = jobs[current_job]
            profit_with_current_job = profit_in_day[job.start - 1] + job.compensation
            highest_possible_profit = max(highest_possible_profit, profit_with_current_job)

            current_job += 1

        profit_in_day.append(highest_possible_profit)

    return profit_in_day[-1]


def main():
    jobs = load_jobs()
    result = highest_profit(jobs)
    print(result)


main()
