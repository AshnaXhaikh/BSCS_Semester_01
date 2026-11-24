# Squeeze Theorem and Fundamental Trigonometric Limits Study Notes

The Squeeze Theorem—also known as the Sandwich Theorem—is a foundational technique in differential calculus used to evaluate the limits of complex or oscillating functions by trapping them between two simpler bounding functions. When combined with geometric principles, the Squeeze Theorem also establishes the fundamental limits of trigonometric functions near zero. This document provides a complete set of study notes covering intuitive foundations, mathematical definitions, geometric proofs, fundamental trigonometric limits, algebraic techniques, and worked practice problems.

---

## 1. Intuitive Foundation: The Calorie Analogy

To grasp how the Squeeze Theorem works before diving into formal calculus, it helps to consider a daily scenario involving three individuals: Imran, Diya, and Sal.

### The Daily Calorie Inequality
On any given day, the caloric intake among the three individuals follows a strict relative order:
* **Imran** always consumes the fewest calories.
* **Sal** always consumes the most calories.
* **Diya** always consumes at least as much as Imran and at most as much as Sal.

Expressing this relationship as a continuous inequality yields:

$$\text{Imran's Calories} \le \text{Diya's Calories} \le \text{Sal's Calories}$$

### The Tuesday Scenario
Suppose that on Tuesday, specific measurements are taken for Imran's and Sal's caloric intake:
* Imran consumed exactly **1,500 calories**.
* Sal consumed exactly **1,500 calories**.

Substituting these numerical values directly into the inequality constrains Diya's intake:

$$1,500 \le \text{Diya's Calories} \le 1,500$$

Because 1,500 is the only real number that is simultaneously greater than or equal to 1,500 and less than or equal to 1,500, Diya **must** have consumed exactly **1,500 calories** on Tuesday.

This common-sense deduction illustrates the core mechanism of the Squeeze Theorem: when an unknown intermediate quantity is constrained between a lower bound and an upper bound, and both boundaries converge to the exact same numerical value, the intermediate quantity is forced to take on that identical value.

---

## 2. Formal Mathematical Definition

In differential calculus, the calorie intake analogy translates to functions of a real variable $x$ evaluated over an interval near a target point $c$.

### Theorem Statement
Let $f(x)$, $g(x)$, and $h(x)$ be functions defined on an open interval containing $x = c$, except possibly at $c$ itself.

If the following two conditions are satisfied:

1. **Bounding Inequality**: For all $x$ in the interval (except possibly at $x = c$),

$$f(x) \le g(x) \le h(x)$$

2. **Equal Outer Limits**: As $x$ approaches $c$, the limit of the lower function $f(x)$ and the limit of the upper function $h(x)$ both exist and equal the same value $L$:

$$\lim_{x \to c} f(x) = L \quad \text{and} \quad \lim_{x \to c} h(x) = L$$

Then the limit of the inner target function $g(x)$ as $x$ approaches $c$ exists and is equal to $L$:

$$\lim_{x \to c} g(x) = L$$

### Key Operating Considerations
* **Domain Flexibility at $c$**: The functions do **not** need to be defined at $x = c$ itself. Limits depend exclusively on the behavior of the functions as $x$ approaches $c$, making the theorem ideal for functions with removable discontinuities or indeterminate forms at $c$.
* **Identical Boundaries Required**: The lower function limit $\lim_{x \to c} f(x)$ and upper function limit $\lim_{x \to c} h(x)$ must evaluate to the exact same value $L$. If the outer limits differ, the Squeeze Theorem cannot be applied.

---

## 3. Graphical Interpretation: The Sandwich Model

The alternative name—the **Sandwich Theorem**—comes from the visual layout of the functions on a Cartesian plane.

### The Sandwich Component Breakdown
When graphing the three functions near $x = c$, each function performs a clear role in the sandwich metaphor.

| Function Role | Mathematical Symbol | Visual / Metaphorical Component |
| :--- | :--- | :--- |
| **Upper Bound** | $h(x)$ | Top slice of bendy bread |
| **Lower Bound** | $f(x)$ | Bottom slice of bendy bread |
| **Target Function** | $g(x)$ | Sandwiched filling / meat |

As $x$ approaches $c$ from either the left or the right, the top slice $h(x)$ and bottom slice $f(x)$ curve inward toward the single height $L$. Because the inner filling $g(x)$ remains trapped between them, it is physically squeezed into the point $(c, L)$.

---
