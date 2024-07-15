import random

def main():
    # Define the topics and the number of problems in each topic
    topics = {
        "Arrays & Hashing": 9,
        "Two Pointers": 5,
        "Sliding Window": 6,
        "Stack": 7,
        "Binary Search": 7,
        "Linked List": 11,
        "Trees": 15,
        "Heap / Priority Queue": 7,
        "Backtracking": 9,
        "Tries": 3,
        "Graphs": 13,
        "Advanced Graphs": 6,
        "1-D Dynamic Programming": 12,
        "2-D Dynamic Programming": 11,
        "Greedy": 8,
        "Intervals": 6,
        "Math & Geometry": 8,
        "Bit Manipulation": 7
    }

    # Randomly select a topic
    topic = random.choice(list(topics.keys()))

    # Randomly select a problem number within the chosen topic
    problem_number = random.randint(1, topics[topic])

    # Print the selected topic and problem number
    print(f"{topic}, problem {problem_number}")

if __name__ == "__main__":
    main()
