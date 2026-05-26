def is_palindrome(s):
    cleaned = ''.join(c.lower() for c in s if c.isalnum())
    return cleaned == cleaned[::-1]

if __name__ == "__main__":
    text = input("Enter a string to check if it's a palindrome: ")
    if is_palindrome(text):
        print(f'"{text}" is a palindrome!')
    else:
        print(f'"{text}" is not a palindrome.')
