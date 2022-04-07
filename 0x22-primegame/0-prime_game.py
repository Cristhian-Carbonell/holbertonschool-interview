#!/usr/bin/python3
"""Prime Game"""
import random


def isWinner(x, nums):
    """Maria and Ben are playing a game.
    Given a set of consecutive integers starting from 1 up to and including n,
    they take turns choosing a prime number from the set and removing that
    number and its multiples from the set. The player that cannot make a move
    loses the game."""
    Maria = 1
    Ben = 0
    winner = {"Maria": 0, "Ben": 0}
    for i in range(x):
        round = nums[i]
        if round == 1:
            if Maria != 0:
                winner["Maria"] += 1
                continue
            else:
                winner["Ben"] += 1
                continue

        newList = random.sample(range(1, round + 1), round)
        element = 0
        for j in range(len(newList)):
            if Maria != 0:
                if len(newList) == 1:
                    winner["Maria"] += 1
                    Maria = 0
                    Ben = 1
                    break
                picks = newList[element]

                if picks == 1:
                    element += 1
                    picks = newList[element]
                index = 0
                for multiples in range(len(newList)):
                    if (len(newList) != 1 and (newList[index] % picks) == 0):
                        newList.pop(index)
                        index -= 1
                        element -= 1
                    index += 1
                Ben = 1
                Maria = 0
                element += 1
            else:
                if len(newList) == 1:
                    winner["Ben"] += 1
                    Ben = 0
                    Maria = 1
                    break
                picks = newList[element]

                if picks == 1:
                    element += 1
                    picks = newList[element]
                index = 0
                for multiples in range(len(newList)):
                    if (len(newList) != 1 and (newList[index] % picks) == 0):
                        newList.pop(index)
                        index -= 1
                        element -= 1
                    index += 1
                Maria = 1
                Ben = 0
                element += 1
    if winner["Maria"] > winner["Ben"]:
        return "Maria"
    elif winner["Ben"] > winner["Maria"]:
        return "Ben"
