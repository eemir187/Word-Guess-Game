# 🔤 Word Guess Game

This is a simple word guessing game written in C. The player has to guess the letters of a hidden word within a limited number of attempts. It plays similarly to classic games like *Hangman*, but with a minimal and straightforward terminal interface.

---

## 🧠 How It Works

- The user is first prompted to enter a secret word (it will be hidden from the guesser).
- The game then begins by asking for letter guesses one at a time.
- Correct guesses reveal the letter in the appropriate position(s).
- Repeated or incorrect guesses reduce the number of remaining attempts.
- The game ends either when the player successfully guesses the entire word or runs out of attempts.

---

## 💻 Example

```text
Word to look for:
 > HELLO

Attempts left: 5
Enter a letter:
 > E
_ E _ _ _

Attempts left: 5
Enter a letter:
 > L
_ E L L _

Attempts left: 5
Enter a letter:
 > X
Letter X was used already!
...
