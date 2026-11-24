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

## 4. Basic Trigonometric Limits as $\theta \to 0$

Before evaluating complex trigonometric limits, we examine the baseline behavior of the primary trigonometric functions—sine, cosine, and tangent—as the angle $\theta$ (measured in radians) approaches zero.

### Behavior of Core Trigonometric Functions
* **Sine Function ($\sin\theta$)**: The sine function is continuous everywhere and passes smoothly through the origin $(0,0)$. As $\theta \to 0$, $\sin\theta \to 0$. Its output is bounded within the range $[-1, 1]$.

$$\lim_{\theta \to 0} \sin\theta = 0$$

* **Cosine Function ($\cos\theta$)**: The cosine function reaches its peak maximum value of $1$ at the origin $(0,1)$ and is continuous near $\theta = 0$. As $\theta \to 0$, $\cos\theta \to 1$. Its output is also bounded within $[-1, 1]$.

$$\lim_{\theta \to 0} \cos\theta = 1$$

* **Tangent Function ($\tan\theta$)**: Since $\tan\theta = \frac{\sin\theta}{\cos\theta}$, its limiting behavior near zero is determined by dividing the individual limits of the numerator and denominator:

$$\lim_{\theta \to 0} \tan\theta = \lim_{\theta \to 0} \frac{\sin\theta}{\cos\theta} = \frac{0}{1} = 0$$

---

## 5. Fundamental Trigonometric Limits

Two classic limit problems involve indeterminate $\frac{0}{0}$ forms that cannot be evaluated by direct substitution. These limits are essential tools throughout calculus and derivation.

### Overview of Fundamental Limits

| Limit Expression | Direct Substitution | Actual Limit Value | Derivation Method |
| :--- | :--- | :--- | :--- |
| $\lim_{\theta \to 0} \frac{\sin\theta}{\theta}$ | $\frac{0}{0}$ (Indeterminate) | **1** | Geometric construction & Squeeze Theorem |
| $\lim_{\theta \to 0} \frac{1 - \cos\theta}{\theta}$ | $\frac{0}{0}$ (Indeterminate) | **0** | Conjugate multiplication & Pythagorean identity |

---

### Geometric Proof of $\lim_{\theta \to 0} \frac{\sin\theta}{\theta} = 1$

To establish this fundamental limit, we construct a geometric inequality using a **unit circle** (a circle with radius $r = 1$) centered at the origin, with a central angle $\theta > 0$ subtending an arc of length $\theta$.

#### 1. Geometric Construction and Areas
Consider three geometric regions created by the angle $\theta$:
1. **Smaller Inner Triangle ($\triangle OAB$)**: Formed by the radius along the horizontal axis, the radius at angle $\theta$, and a vertical line segment of height $\sin\theta$.
   $$\text{Area}(\triangle OAB) = \frac{1}{2} \cdot \text{base} \cdot \text{height} = \frac{1}{2} (1) (\sin\theta) = \frac{1}{2}\sin\theta$$

2. **Circular Sector ($OAB$)**: The wedge of the unit circle bounded by the arc of length $\theta$. Using the sector area formula $\frac{1}{2}r^2\theta$ with $r = 1$:
   $$\text{Area}(\text{Sector } OAB) = \frac{1}{2} (1)^2 \theta = \frac{1}{2}\theta$$

3. **Bigger Outer Triangle ($\triangle OAC$)**: Extended to a vertical tangent line at $(1,0)$ with height $\tan\theta$.
   $$\text{Area}(\triangle OAC) = \frac{1}{2} \cdot \text{base} \cdot \text{height} = \frac{1}{2} (1) (\tan\theta) = \frac{1}{2}\tan\theta$$

#### 2. Establishing the Area Inequality
Visual inspection confirms that the inner triangle is contained inside the sector, which is contained inside the outer triangle:

$$\text{Area}(\triangle OAB) < \text{Area}(\text{Sector } OAB) < \text{Area}(\triangle OAC)$$

$$\frac{1}{2}\sin\theta < \frac{1}{2}\theta < \frac{1}{2}\tan\theta$$

#### 3. Algebraic Manipulation
Multiply the entire inequality by $2$ to eliminate fractions:

$$\sin\theta < \theta < \tan\theta$$

Since $\sin\theta > 0$ for small positive angles $\theta$, divide all three terms by $\sin\theta$:

$$1 < \frac{\theta}{\sin\theta} < \frac{\tan\theta}{\sin\theta}$$

Substituting $\tan\theta = \frac{\sin\theta}{\cos\theta}$ simplifies the right-hand term:

$$1 < \frac{\theta}{\sin\theta} < \frac{1}{\cos\theta}$$

Taking the reciprocal of all terms reverses the inequality signs:

$$\cos\theta < \frac{\sin\theta}{\theta} < 1$$

#### 4. Applying the Squeeze Theorem
Now take the limit as $\theta \to 0^+$ across all three terms:

$$\lim_{\theta \to 0^+} \cos\theta = 1 \quad \text{and} \quad \lim_{\theta \to 0^+} 1 = 1$$

Because the target function $\frac{\sin\theta}{\theta}$ is trapped between $\cos\theta$ and $1$, and both outer functions approach $1$ as $\theta \to 0$, the Squeeze Theorem dictates:

$$\lim_{\theta \to 0} \frac{\sin\theta}{\theta} = 1$$

---

### Algebraic Proof of $\lim_{\theta \to 0} \frac{1 - \cos\theta}{\theta} = 0$

Evaluating $\lim_{\theta \to 0} \frac{1 - \cos\theta}{\theta}$ directly gives $\frac{1 - 1}{0} = \frac{0}{0}$. We resolve this using conjugate multiplication and the fundamental limit derived above.

#### Step 1: Multiply by the Conjugate
Multiply the numerator and denominator by $(1 + \cos\theta)$:

$$\frac{1 - \cos\theta}{\theta} = \frac{(1 - \cos\theta)(1 + \cos\theta)}{\theta(1 + \cos\theta)} = \frac{1 - \cos^2\theta}{\theta(1 + \cos\theta)}$$

#### Step 2: Apply the Pythagorean Identity
Use the identity $1 - \cos^2\theta = \sin^2\theta$:

$$= \frac{\sin^2\theta}{\theta(1 + \cos\theta)}$$

#### Step 3: Separate into Known Factors
Split the fraction into two separate factors to isolate the known limit $\frac{\sin\theta}{\theta}$:

$$= \left(\frac{\sin\theta}{\theta}\right) \cdot \left(\frac{\sin\theta}{1 + \cos\theta}\right)$$

#### Step 4: Evaluate the Limit of Each Factor
Apply the product rule for limits as $\theta \to 0$:

$$\lim_{\theta \to 0} \frac{1 - \cos\theta}{\theta} = \left(\lim_{\theta \to 0} \frac{\sin\theta}{\theta}\right) \cdot \left(\lim_{\theta \to 0} \frac{\sin\theta}{1 + \cos\theta}\right)$$

Substitute the known values ($\lim_{\theta \to 0} \frac{\sin\theta}{\theta} = 1$ and $\sin 0 = 0, \cos 0 = 1$):

$$= 1 \cdot \left(\frac{0}{1 + 1}\right) = 1 \cdot \left(\frac{0}{2}\right) = 0$$

Thus, the fundamental trigonometric limit is established:

$$\lim_{\theta \to 0} \frac{1 - \cos\theta}{\theta} = 0$$

---

## 6. Practical Application Strategies & Worked Examples

The Squeeze Theorem is particularly effective for limits involving oscillating functions such as $\sin\left(\frac{1}{x}\right)$ or $\cos(x)$, where direct evaluation fails due to non-stop oscillation near $x = 0$.

### Example 1: Bounding an Oscillating Cosine Expression

**Problem**: Evaluate $\lim_{x \to 0} |x|\cos x$.

#### Solution Walkthrough:
1. **Establish Range Bounds**: Start with the known range of the cosine function:

$$-1 \le \cos x \le 1$$

2. **Multiply by $|x|$**: Since the absolute value $|x| \ge 0$ for all real numbers $x$, multiplying through preserves the inequality directions:

$$-|x| \le |x|\cos x \le |x|$$

3. **Evaluate Outer Limits**: Take the limit as $x \to 0$ for the left and right bounding expressions:

$$\lim_{x \to 0} (-|x|) = 0 \quad \text{and} \quad \lim_{x \to 0} |x| = 0$$

4. **Apply Squeeze Theorem**: Since both outer limits equal $0$, the central function is squeezed to $0$:

$$\lim_{x \to 0} |x|\cos x = 0$$

---

### Example 2: Quadratic Oscillating Function

**Problem**: Evaluate $\lim_{x \to 0} x^2 \sin\left(\frac{1}{x}\right)$.

#### Solution Walkthrough:
1. **Establish Range Bounds**: As $x \to 0$, the expression $\frac{1}{x}$ approaches infinity, causing $\sin\left(\frac{1}{x}\right)$ to oscillate rapidly. However, its value strictly remains within $[-1, 1]$:

$$-1 \le \sin\left(\frac{1}{x}\right) \le 1 \quad \text{for all } x \neq 0$$

2. **Multiply by $x^2$**: Multiply the entire inequality by $x^2$ (which is always non-negative):

$$-x^2 \le x^2 \sin\left(\frac{1}{x}\right) \le x^2$$

3. **Evaluate Outer Limits**: Calculate the limits of the bounding functions as $x \to 0$:

$$\lim_{x \to 0} (-x^2) = 0 \quad \text{and} \quad \lim_{x \to 0} x^2 = 0$$

4. **Apply Squeeze Theorem**: Both lower and upper bounds converge to $0$, forcing the middle function to converge to $0$:

$$\lim_{x \to 0} x^2 \sin\left(\frac{1}{x}\right) = 0$$

---

## 7. Comprehensive Summary & Reference Cheat Sheet

* **Core Concept**: Trapping an intermediate function $g(x)$ between $f(x)$ and $h(x)$ such that $f(x) \le g(x) \le h(x)$.
* **Convergence Rule**: If $\lim_{x \to c} f(x) = L$ and $\lim_{x \to c} h(x) = L$, then $\lim_{x \to c} g(x) = L$.
* **Baseline Limits ($\theta \to 0$)**:
  * $\lim_{\theta \to 0} \sin\theta = 0$
  * $\lim_{\theta \to 0} \cos\theta = 1$
  * $\lim_{\theta \to 0} \tan\theta = 0$
* **Fundamental Trigonometric Limits**:
  * $\lim_{\theta \to 0} \frac{\sin\theta}{\theta} = 1$
  * $\lim_{\theta \to 0} \frac{1 - \cos\theta}{\theta} = 0$
* **Primary Utility**: Solving indeterminate $\frac{0}{0}$ forms and dampening rapidly oscillating trigonometric expressions near boundary points.
