# FdF: From Height Values to a View I Could Move

When I started FdF, graphics programming was unfamiliar territory. The project
came from the 42 curriculum, and that was part of its value: it asked me to
work in an area I might not have chosen on my own. The task was to take a text
map of heights and turn it into a wireframe landscape. I understood the goal;
the question was how to make the first visible result happen.

At first, even deciding what to build first was not obvious. I could try to
print the points, but a set of coordinates would not mean much on screen unless
I could scale and orient them into a useful view. I had to build the path from
input to image piece by piece: read and validate the map, place its points,
transform them, and finally connect them. The progress was incremental. First
I worked toward displaying points; then the landscape began to take shape as
I drew the edges between neighboring points.

The line drawing was one of the hardest parts. I enjoy mathematics, but
knowing the idea behind Bresenham's algorithm did not automatically tell me
how to implement it. A geometric line has to become a sequence of individual
pixel steps. I had to understand what to initialize, which direction to move,
and when the accumulated error meant the other coordinate should advance.
Those implementation details made the difference between understanding the
algorithm on paper and seeing it work in the image buffer.

MiniLibX was another learning curve. It took time to understand how to create
the window, work with its image buffer, and respond to events. Conversations
with colleagues helped me get through that part faster. As the basic renderer
came together, I added rotation, zoom, and panning, then separated the
interactive controls into a bonus version with projection switching and
independent height scaling.

Rotation became the part I was proudest of. The finished operation can look
small in code, but applying rotations around three axes meant understanding
the matrices and fitting examples I had studied into this project's own
coordinate and rendering flow. Adapting the logic was harder than copying a
formula. Getting the map to respond to the controls made that effort visible:
I could change the view and immediately see the terrain move.

That visual feedback was powerful, but it did not solve every debugging
problem. Sometimes the image showed that something was wrong without showing
why. I used GDB to inspect functions and added guards for failure cases; when
the visual symptom was unclear, knowing how the connected code worked helped
me trace it. The project grew into many files and functions that depended on
one another, so robustness became part of the work. Over time, I addressed
problems such as failed file opens, empty maps, inconsistent row sizes, zoom
behavior, and resource cleanup. Peer evaluation added another reason to think
carefully about cases beyond the map that happened to work on my screen.

By the end, a plain grid of height values could become a terrain I could
inspect from different angles and interact with. That was the most rewarding
part: not only seeing the result, but being able to change it myself. FdF gave
me a first taste of graphics programming and helped me appreciate the
complexity behind visuals that are easy to take for granted in everyday
software and games.