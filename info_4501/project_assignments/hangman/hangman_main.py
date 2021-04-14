import random
import string

WORDLIST_FILENAME = "words.txt"


def load_words():
    """
    Returns a list of valid words. Words are strings of lowercase letters.

    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist


def choose_word(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code

# -----------------------------------


def check_remaining_warning_guess(nWarning, nGuess):
    if nWarning > 0:
        # all 3 warnings have not been used
        nWarning += -1
        print(f"You now have {nWarning} warnings and {nGuess} guesses left.")
        return nWarning, nGuess
    else:
        # user has no more warnings
        nGuess += -1
        print(f"You have no more warnings, a guess was removed. You now have {nGuess} guesses left.")
        return nWarning, nGuess



def get_input(vocab, nWarning, nGuess):

    while True:
        print()
        print(f"Available letters: {''.join([char for char in vocab if vocab[char] != 1])}")
        guess = input("Please enter a lettter to guess: ")

        if len(guess) == 1:
            if guess.isalpha():
                guess = guess.lower()
                if vocab[guess] == 0:
                    # guess has not been chosen before
                    return guess, nWarning, nGuess
                else:
                    # WARNING -- already guessed letter
                    print("Oops! You have already guessed that letter.")
                    nWarning, nGuess = check_remaining_warning_guess(nWarning, nGuess)
                    pass
            elif guess is "!":
                return "dev", nWarning, nGuess
            elif guess is "*":
                return "match", nWarning, nGuess
            else:
                # WARNING -- guess is not an allowable character
                print("Oops! That guess is not an allowable character.")
                nWarning, nGuess = check_remaining_warning_guess(nWarning, nGuess)
                pass
        else:
            # WARNING -- guess is more than one character
            print("Oops! That guess is more than one character.")
            nWarning, nGuess = check_remaining_warning_guess(nWarning, nGuess)
            pass

        if nGuess < 0:
            # user has no more guesses left
            return None, None, None


def find_all_matches(current_guess, wordlist):
    possible_matches = {word:0 for word in wordlist if len(word) is len(current_guess)}
    for word in possible_matches:
        for i, char in enumerate(current_guess):
            if char != '_':
                if char != word[i]:
                    break

            if i == len(word) - 1:
                possible_matches[word] = 1
    matches = [word for word in possible_matches if possible_matches[word] == 1]
    return matches


def check_guess(guess, previous_nCorrect, nCorrect):
    # modify variables for newest guess

    if previous_nCorrect == nCorrect:
        if guess in ['a', 'e', 'i', 'o', 'u']: # 'y' does not count as a vowel
            # guess is a vowel
            print("Oops! That letter is not in my word. Unfortunately, that letter is a vowel. You lose 2 guesses.")
            return -2
        else: 
            # guess is a constant
            print("Oops! That letter is not in my word. Fortunately, that letter is a constant. You lost 1 guess.")
            return -1
        
    elif previous_nCorrect < nCorrect:
        # user correctly guessed a character
        print("Good guess!")
        return 0
    else:
        # this shouldnt happen
        print("Something went wrong with the truth list.")
        print("Terminating game early.")
        quit()


def main():
    vocab = dict.fromkeys(string.ascii_lowercase, 0) # grab letters a - 2
    wordlist = load_words() # load wordlist from text file
    chosen_word = choose_word(wordlist) # choose a word randomly
    chosen_truth = [0 for i in range(len(chosen_word))] # set up an array for each correctly chosen letter

    print()
    print("Welcome to the game Hangman!")
    print(f"I am thinking of a word that is {len(chosen_word)} letters long")

    nGuess = 6 # number of remaining guesses
    nWarning = 3 # number of remaining warnings
    previous_nCorrect = 0 # number of guesses that are correct for the previous guess

    while True:
        # printing statements ############
        print("------------------")
        if nGuess != 1:
            print(f"you have {nGuess} guesses left.")
        else:
            print(f"you have {nGuess} guess left.")
        
        # prints currently found word
        print(" ".join(['_' if chosen_truth[i] == 0 else char
                        for i, char in enumerate(chosen_word)]))

        guess, nWarning, nGuess = get_input(vocab, nWarning, nGuess)  # get guess from user

        # update guess values
        if guess is "dev": # development mode
            print()
            print("Development mode activated...")
            print(f"The chosen word to guess is: {chosen_word}")
        elif guess is "match": # find all matches to the current found word
            current_word = "".join(['_' if chosen_truth[i] == 0 else char 
                                    for i, char in enumerate(chosen_word)])
            
            matches = find_all_matches(current_word, wordlist)
            print("Possible word matches are:")
            print(" ".join(matches))
        elif guess is None: # get_input function noted user has lost
            print()
            print("Sorry, you have ran out of guesses. The word to guess was: {chosen_word}.")
            print("Game is over.")
            break
        else: # guess was valid
            vocab[guess] = 1
            
            previous_nCorrect = sum(chosen_truth) # update previous number of correct characters
            # create a new array for correct characters
            chosen_truth = [0 if vocab[char] == 0 else 1
                            for char in chosen_word]
            
            nCorrect = sum(chosen_truth) # get new number of correct characters
            nGuess += check_guess(guess, previous_nCorrect, nCorrect) # check the previous vs current number of correct characters

        if len(chosen_word) == sum(chosen_truth): # word was fully guessed correctly
            points = nGuess * len(list(set(chosen_word)))
            print()
            print(f"Congratulations! You have correctly guessed the word: {chosen_word}!")
            print(f"Your total score for this game is: {points}")
            print("Game is over.")
            break
        elif nGuess < 0: # user ran out of guesses
            print()
            print(f"Sorry, you have ran out of guesses. The word to guess was: {chosen_word}.")
            print("Game is over.")
            break


if __name__ == "__main__":
    main()