import tkinter as tk

def is_palindrome(s):
    cleaned = ''.join(c.lower() for c in s if c.isalnum())
    return cleaned == cleaned[::-1]

def check_palindrome():
    text = entry.get()
    if is_palindrome(text):
        result_label.config(text=f'"{text}" is a palindrome!')
    else:
        result_label.config(text=f'"{text}" is not a palindrome.')

root = tk.Tk()
root.title("Palindrome Checker")

label = tk.Label(root, text="Enter a string to check:")
label.pack(pady=10)

entry = tk.Entry(root, width=50)
entry.pack(pady=5)

check_button = tk.Button(root, text="Check", command=check_palindrome)
check_button.pack(pady=10)

result_label = tk.Label(root, text="")
result_label.pack(pady=10)

root.mainloop()
