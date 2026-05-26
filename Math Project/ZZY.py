# import requests

# url = "https://api.npoint.io/4a93a205d2d6039f5bc9/why/0"


# response = requests.get(url)

# print(response.json())
i=1

import pyautogui
import time
time.sleep(3)
initial_position=pyautogui.position()

# for i in range(7804570,7810000):
#     pyautogui.write(str(i))
#     pyautogui.press('enter')
#     pyautogui.click(initial_position)

for a in range(200,220):
    for b in range(200,220):
        for c in range(200,220):
            st=f'<color name="color{i}">#{hex(a).removeprefix(r'0x')}{hex(b).removeprefix(r'0x')}{hex(c).removeprefix(r'0x')}</color>'
            pyautogui.write(st)
            pyautogui.press('enter')
            pyautogui.click(initial_position)
            i+=1

# print(hex(255).removeprefix(r'0x'))