# import pygame
# import sys

# # Initialize Pygame
# pygame.init()

# value=[]
# with open("./output/polygon.txt",mode="r") as file:
#     data = file.readlines()
#     for i in data:
#         x,y=map(float,i.split())
#         value.append(((-x+10)*50,(-y+10)*50))
# # Create a screen
# screen = pygame.display.set_mode((800, 600))
# pygame.display.set_caption("Pygame Example")

# # Define colors
# WHITE = (255, 255, 255)
# RED = (255, 0, 0)

# # Main loop
# running = True
# while running:
#     for event in pygame.event.get():
#         if event.type == pygame.QUIT:
#             running = False

#     # Fill the screen with white
#     screen.fill(WHITE)

#     # Draw a red polygon
#     pygame.draw.polygon(screen,"dark green", value)
#     pygame.transform.rotate(screen,180.0)


#     # Update the display
#     pygame.display.flip()

# # Quit Pygame
# pygame.quit()
# sys.exit()



a=10
b=2
a,b=b,a
print(a,b)

