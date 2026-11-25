# Continuity at a Point: The Three Conditions (Topic 054 Study Notes)

Continuity is a foundational concept in differential calculus that formalizes what it means for a mathematical function to behave smoothly without unexpected interruptions. While limit calculations describe how a function behaves as $x$ approaches a given value, continuity connects that limiting behavior directly to the function's actual value at that point. As presented in the Virtual University of Pakistan Calculus 1 series (Topic 054), this study guide details the intuitive meaning of continuity, the three formal mathematical conditions required for continuity at a point, a step-by-step decision algorithm for evaluating functions, and detailed case studies illustrating both continuous behavior and different modes of discontinuity.

---

## 1. Intuitive Concept of Continuity

Before introducing formal mathematical definitions, it is helpful to conceptualize continuity geometrically and visually.

### The Pencil Test and Graphical Smoothness
At an intuitive level, a function $f(x)$ is continuous at a point $x = a$ if its graph near $x = a$ contains no breaks, holes, or jumps:

* **The Pencil Rule**: A curve drawn on paper is continuous if you can trace or draw the curve across the point $x = a$ without lifting your pencil from the page.
* **Lack of Interruption**: As the input variable $x$ moves smoothly toward $a$, the output path $f(x)$ transitions seamlessly without sudden steps or missing points.

While this intuitive picture provides immediate visual insight, calculus requires precise mathematical criteria to test whether a function is continuous at any given point $x = a$.

---

## 2. The Three Formal Conditions of Continuity

In calculus, a function $f(x)$ is defined to be continuous at a specific point $x = a$ if and only if three distinct mathematical conditions are simultaneously satisfied. If even a single condition fails, the function is classified as **discontinuous** at $x = a$.

### The Three Conditions

1. **Condition 1: Function Definition**  
   The function value $f(a)$ must be defined. That is, $x = a$ must belong to the domain of $f(x)$, producing a finite real output.

2. **Condition 2: Limit Existence**  
   The limit of $f(x)$ as $x$ approaches $a$ must exist:
   $$\lim_{x \to a} f(x) = L$$
   For this limit to exist, both the left-hand limit and the right-hand limit as $x$ approaches $a$ must be finite and equal:
   $$\lim_{x \to a^-} f(x) = \lim_{x \to a^+} f(x) = L$$

3. **Condition 3: Equality of Limit and Function Value**  
   The limiting value of the function as $x$ approaches $a$ must equal the actual function value evaluated at $a$:
   $$\lim_{x \to a} f(x) = f(a)$$

### Summary Breakdown of the Three Conditions

The following table summarizes the purpose and failure modes of each of the three continuity conditions:

| Condition | Mathematical Statement | Core Requirement | Common Cause of Failure |
| :--- | :--- | :--- | :--- |
| **Condition 1** | $f(a)$ is defined | $x = a$ is in the domain | Division by zero or $0/0$ indeterminate form |
| **Condition 2** | $\lim_{x \to a} f(x)$ exists | Left-hand limit equals right-hand limit | Jump between piecewise function branches |
| **Condition 3** | $\lim_{x \to a} f(x) = f(a)$ | Limit value equals function value | Isolated point defined away from the curve hole |

---

## 3. Step-by-Step Continuity Decision Algorithm

To evaluate whether a function $f(x)$ is continuous at a point $x = a$, follow a systematic three-step testing strategy. Proceed sequentially from Step 1 to Step 3; if any step fails, stop immediately and conclude that the function is discontinuous.

### Step-by-Step Procedure

1. **Step 1: Evaluate the Function Value $f(a)$**  
   Substitute $x = a$ directly into the original expression for $f(x)$.
   * *If $f(a)$ is undefined* (such as producing a zero denominator), stop immediately. Conclude that **$f(x)$ is not continuous at $x = a$ due to failure of Condition 1**.
   * *If $f(a)$ yields a real number*, proceed to Step 2.

2. **Step 2: Determine the Limit $\lim_{x \to a} f(x)$**  
   Calculate the limit as $x$ approaches $a$. For piecewise functions or functions with different expressions on either side of $a$, evaluate the left-hand limit $\lim_{x \to a^-} f(x)$ and right-hand limit $\lim_{x \to a^+} f(x)$ separately.
   * *If the limit does not exist* ($\lim_{x \to a^-} f(x) \neq \lim_{x \to a^+} f(x)$ or approaches $\pm\infty$), stop immediately. Conclude that **$f(x)$ is not continuous at $x = a$ due to failure of Condition 2**. (Note: In piecewise functions, border points between sub-domains frequently fail Condition 2).
   * *If the limit exists and equals a finite number $L$*, proceed to Step 3.

3. **Step 3: Compare the Limit Value and Function Value**  
   Check whether $\lim_{x \to a} f(x) = f(a)$.
   * *If $\lim_{x \to a} f(x) \neq f(a)$*, conclude that **$f(x)$ is not continuous at $x = a$ due to failure of Condition 3**.
   * *If $\lim_{x \to a} f(x) = f(a)$*, conclude that **$f(x)$ is continuous at $x = a$**.

---

## 4. Case Studies & Worked Examples

Examining specific mathematical scenarios demonstrates how each of the three conditions operates in practice.

### Case 1: Failure of Condition 1 (Undefined Function Value)
Consider evaluating the rational function $f(x) = \frac{x^2 - 9}{x - 3}$ at the point $x = 3$.

1. **Step 1 Check**: Evaluate $f(3)$ directly:
   $$f(3) = \frac{3^2 - 9}{3 - 3} = \frac{0}{0}$$
   Because division by zero is undefined, $f(3)$ does not exist.
2. **Decision**: The process stops at Step 1. The function $f(x)$ is **not continuous at $x = 3$** because Condition 1 fails.

*Insight on Limit Behavior*: Although $f(3)$ is undefined, the limit as $x \to 3$ does exist:
$$\lim_{x \to 3} \frac{x^2 - 9}{x - 3} = \lim_{x \to 3} \frac{(x - 3)(x + 3)}{x - 3} = \lim_{x \to 3} (x + 3) = 6$$
Graphically, this represents a removable discontinuity (a hole in the line $y = x + 3$ at $x = 3$). However, the existence of the limit cannot override the failure of Condition 1.

---

### Case 2: Failure of Condition 2 (Limit Does Not Exist)
Consider a piecewise function $g(x)$ evaluated at its boundary point $x = 2$:
$$g(x) = \begin{cases} x^2 - 7 & \text{for } x < 2 \\ 3x - 5 & \text{for } x \ge 2 \end{cases}$$

1. **Step 1 Check**: Evaluate $g(2)$ using the formula for $x \ge 2$:
   $$g(2) = 3(2) - 5 = 6 - 5 = 1$$
   Condition 1 passes because $g(2) = 1$ is defined.

2. **Step 2 Check**: Evaluate one-sided limits as $x$ approaches $2$:
   * Left-hand limit ($x \to 2^-$):
     $$\lim_{x \to 2^-} g(x) = \lim_{x \to 2^-} (x^2 - 7) = 2^2 - 7 = 4 - 7 = -3$$
   * Right-hand limit ($x \to 2^+$):
     $$\lim_{x \to 2^+} g(x) = \lim_{x \to 2^+} (3x - 5) = 3(2) - 5 = 1$$
   Since $-3 \neq 1$, the left-hand limit and right-hand limit are unequal. Thus, $\lim_{x \to 2} g(x)$ **does not exist**.

3. **Decision**: The process stops at Step 2. The function $g(x)$ is **not continuous at $x = 2$** because Condition 2 fails. Graphically, this represents a jump discontinuity.

---

### Case 3: Satisfaction of All Three Conditions (Continuous Function)
Consider a piecewise function $h(x)$ combining a trigonometric expression with a defined point at $x = 0$:
$$h(x) = \begin{cases} \frac{\sin x}{x} & \text{for } x \neq 0 \\ 1 & \text{for } x = 0 \end{cases}$$

1. **Step 1 Check**: Evaluate $h(0)$ directly using the explicit point definition:
   $$h(0) = 1$$
   Condition 1 is satisfied ($h(0)$ is defined).

2. **Step 2 Check**: Evaluate the limit as $x \to 0$:
   $$\lim_{x \to 0} h(x) = \lim_{x \to 0} \frac{\sin x}{x} = 1$$
   By the fundamental trigonometric limit (proven via the Squeeze Theorem), the limit exists and equals $1$. Condition 2 is satisfied.

3. **Step 3 Check**: Compare the limit value to the function value:
   $$\lim_{x \to 0} h(x) = 1 = h(0)$$
   Condition 3 is satisfied.

4. **Decision**: All three conditions pass. The function $h(x)$ is **continuous at $x = 0$**. The point definition $h(0) = 1$ perfectly fills what would otherwise be a hole in $\frac{\sin x}{x}$.

---

## 5. Critical Distinction: Direct Substitution vs. Algebraic Simplification

A common pitfall when analyzing continuity involves premature algebraic simplification.

### The Rule for Checking $f(a)$
When testing Condition 1 ($f(a)$ is defined), you **must plug $a$ directly into the original un-simplified expression of the function**.

* **Why Simplification Is Forbidden in Step 1**: Algebraic simplification (such as factoring $\frac{x^2 - 9}{x - 3}$ to $x + 3$) relies on canceling terms like $\frac{x - 3}{x - 3}$. Cancellation is mathematically valid only when $x - 3 \neq 0$ (meaning $x \neq 3$). Therefore, simplifying alters the domain of the function.
* **Where Simplification Is Allowed**: Algebraic simplification is completely valid during **Step 2 (evaluating limits)**, because limits examine function behavior as $x$ *approaches* $a$, strictly excluding the point $x = a$ itself.

---

## 6. Summary Checklist for Continuity Testing

When completing continuity problems on coursework or exams, review this quick verification checklist:

* Evaluated $f(a)$ using the **original, un-simplified** function expression.
* Confirmed whether $f(a)$ is a finite real number (Condition 1).
* Tested both left-hand and right-hand limits if evaluating a piecewise function (Condition 2).
* Verified whether $\lim_{x \to a} f(x)$ equals a finite real number $L$ (Condition 2).
* Checked that the numerical value of the limit exactly matches $f(a)$ (Condition 3).
