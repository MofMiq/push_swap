# Push_swap
> This repository contains a "Push_swap" project that is part of the École 42 curriculum.

This project will require you to sort data in a stack using a limited set of instructions and using the minimum number of instructions possible. To succeed, you will need to experiment with various algorithms and choose the most appropriate one for optimal sorting.

![](https://github.com/MofMiq/push_swap/blob/main/arg%20copy.gif)

## Instructions

- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

## Grading

The grade is on a scale from 0 to 100 (validating the project requires at least 80/100), and is based on the following criteria:

- 3 numbers to sort: no more than 3 instructions.
- 5 numbers to sort: no more than 12 instructions.
- 100 numbers to sort:
  - 5 points for less than 700 instructions.
  - 4 points for less than 900 instructions.
  - 3 points for less than 1100 instructions.
  - 2 points for less than 1300 instructions.
  - 1 point for less than 1500 instructions.
  - 0 point for more than 1500 instructions.
- 500 numbers to sort:
  - 5 points for less than 5500 instructions.
  - 4 points for less than 7000 instructions.
  - 3 points for less than 8500 instructions.
  - 2 points for less than 10000 instructions.
  - 1 point for less than 11500 instructions.
  - 0 point for more than 11500 instructions.

![](https://github.com/MofMiq/push_swap/blob/main/visualizer.gif)

## Structure

```c
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;
```
- value: the number itself.
- index: it's index in the list of all values that must be sorted.
- pos: the position of the number in the stack.
- target_pos: the position the number should be in the stack A.
- cost_a: the cost of moving the number to its right position in stack A.
- cost_b: the cost of moving the number to the top of stack B.
- next: the pointer to the next element in the stack.


## Algorithm

- Assigning Indexes
  - Once we’ve filled our stack A with the values to sort, we need to assign each element an index, from smallest to biggest. For practical reasons, the index will start at 1 and end at the total number of values to sort.
- Sorting 3 numbers
  - For three numbers, there are only six possible cases (including the case where they are already sorted). Therefore, we will manually sort them using the element in the stack with the highest index as a reference. This way, we ensure that the three numbers are sorted in 2 or fewer actions.
- Sorting more than 3 numbers
  - We sort three elements separately because there are only five possible cases, excluding the one case where the numbers are already sorted, and this way, we ensure that it's sorted in two moves or fewer. Also, we make a previous ordenation pushing first the ones with smaller indixes.
  - We sort the 3 numbers left in stack A. With these three values in order, all we need to do is insert each element in stack B at the right position in stack A.
  - Finding the current position withing the stack.
  - Finding the target postion, where an element of stack B needs to be in stack A. We can spot this target position simply by scanning stack A for the closest superior index to the one of the stack B element. This is important because we will be able to determine how many actions it will take to get each stack in the right position for each element.
  - Calculating cost in Stack A and Stack B to determine how many actions are needed to move the stacks to their correct positions. In addition, we divide both stack in two halves because we're going to do rotate for the top half and reverse rotate for the bottom. Futhermore, we will make the cost of reverse rotate negative so that when we have to make the movements, we know immediately which rotate to make just by looking at the sign.
  - Choosing the cheapest cost
  - Executing the chosen sequence of actions. If both costs are positive, we rotate both stacks to save moves until one of them reaches 0. Otherwise, if both cost are negative, we must do reverse rotate in both stack as we have done previously. When one of the cost becomes 0 means that we don't have to make more moves in one stack, so we make the aproppiate moves (rotate or reverse) in the other stack.
  - Shift the already sorted stack_a but getting it in the rigth position.

## BONUS

For the bonus you have to check if the stack is sorted using the given instructions, so we use our function `get_next_line` to read from the 0 (standard input), for each line entered, we compare it with our known instructions, if the input doesn't match with any of them, we must display `Error` in the standard error, otherwise we execute the proper instruction on our stack. If the list is sorted with the inputs given, we print OK; otherwise, we print KO.

![](https://github.com/MofMiq/push_swap/blob/main/bonus.gif)

Subject version: 6
