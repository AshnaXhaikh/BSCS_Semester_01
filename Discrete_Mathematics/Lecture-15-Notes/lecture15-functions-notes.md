# MTH202 Discrete Mathematics — Lecture 15: Functions

## 1. Introduction & Historical Context

The concept of a **function** is one of the most fundamental building blocks in mathematics, computer science, and software engineering. While mathematical relationships have been utilized for millennia, the formal, rigorous definition of a function used today took centuries to develop and was finalized in the early $19^\text{th}$ century.

In discrete mathematics, functions are treated as a specialized class of **binary relations**. While any arbitrary collection of ordered pairs between two sets forms a relation, a function imposes strict structural constraints on how elements of the domain map to the target set.

---

## 2. Relation-Based Formal Definition of a Function

A binary relation $f$ from a set $X$ to a set $Y$ (written as $f \subseteq X \times Y$) is defined as a **function** if and only if it satisfies two essential criteria simultaneously:

> **Formal Definition (Relation-Based):**
> A relation $f$ from $X$ to $Y$ is a function from $X$ to $Y$ (denoted $f: X \to Y$) if:
> 1. **Everywhere Defined Property (Total Domain):**
>    $$\forall x \in X, \, \exists y \in Y \text{ such that } (x, y) \in f$$
>    Every element in the domain $X$ must appear as the first element of at least one ordered pair in $f$.
> 2. **Uniqueness Property (Single-Valued):**
>    $$\forall x \in X \text{ and } \forall y, z \in Y, \, \Big((x, y) \in f \land (x, z) \in f\Big) \implies y = z$$
>    No element in the domain $X$ can map to two distinct elements in $Y$. That is, no two distinct ordered pairs in $f$ share the same first element.

---

### Step-by-Step Analysis of Candidate Relations

To master how to test whether a given relation is a function, consider the domain $X = \{2, 4, 5\}$ and the target set $Y = \{1, 2, 4, 6\}$. Examine the following three binary relations:

#### Case 1: $R_1 = \{(2, 4), (4, 1)\}$
* **Check Property 1 (Everywhere Defined):** Examine domain $X = \{2, 4, 5\}$. The element $5 \in X$ does **not** appear as the first element of any pair in $R_1$.
* **Verdict:** **Not a function** ❌ (Fails the Everywhere Defined property because $5$ is unmapped).

#### Case 2: $R_2 = \{(2, 4), (4, 1), (4, 2), (5, 6)\}$
* **Check Property 1:** Elements $2, 4, 5$ all appear as first elements.
* **Check Property 2 (Uniqueness):** Look at the element $4 \in X$. It appears in two distinct ordered pairs: $(4, 1) \in R_2$ and $(4, 2) \in R_2$, mapping $4$ to both $1$ and $2$.
* **Verdict:** **Not a function** ❌ (Fails the Uniqueness property because $4$ maps to two distinct targets).

#### Case 3: $R_3 = \{(2, 4), (4, 2), (5, 6)\}$
* **Check Property 1:** Domain elements $2, 4, 5$ are all mapped.
* **Check Property 2:** $2$ maps uniquely to $4$, $4$ maps uniquely to $2$, and $5$ maps uniquely to $6$.
* **Verdict:** **Is a valid function** ✅ (Satisfies both Everywhere Defined and Uniqueness properties).

---

### Worked Exercise: Set Relations as Functions

Let set $A = \{4, 5, 6\}$ and set $B = \{5, 6\}$. Evaluate two binary relations from $A$ to $B$:

1. **Relation $R$ defined as $x R y \iff x \ge y$:**
   * Constructing ordered pairs from $A \times B$:
     * $4$ is not $\ge 5$ or $6$ (no pairs starting with $4$).
     * $5 \ge 5 \implies (5, 5)$.
     * $6 \ge 5$ and $6 \ge 6 \implies (6, 5)$ and $(6, 6)$.
   * Resulting set: $R = \{(5, 5), (6, 5), (6, 6)\}$.
   * **Evaluation:** $R$ is **not a function** ❌. $4 \in A$ is unmapped (violates Everywhere Defined), and $6 \in A$ maps to both $5$ and $6$ (violates Uniqueness).

2. **Relation $S$ defined as $x S y \iff 2 \mid (x - y)$:**
   * Constructing ordered pairs:
     * $4 - 5 = -1$ (not div by 2); $4 - 6 = -2$ (div by 2) $\implies (4, 6)$.
     * $5 - 5 = 0$ (div by 2); $5 - 6 = -1$ (not div by 2) $\implies (5, 5)$.
     * $6 - 5 = 1$ (not div by 2); $6 - 6 = 0$ (div by 2) $\implies (6, 6)$.
   * Resulting set: $S = \{(4, 6), (5, 5), (6, 6)\}$.
   * **Evaluation:** $S$ **is a valid function** ✅. Every element in $A = \{4, 5, 6\}$ maps to a unique element in $B$.

---

## 3. Mapping-Based Definition & Fundamental Terminology

When defined independently of set-theoretic relations, a function is framed as an assignment or mapping between two sets:

> **Formal Definition (Mapping-Based):**
> A function $f$ from a set $X$ to a set $Y$ (written $f: X \to Y$) is a rule or mechanism that assigns to **each** element $x \in X$ a **unique** element $y \in Y$.

### Core Components of Functions

* **Domain:** The input set $X$. Every element $x \in X$ must have an output.
* **Co-domain:** The targeted output set $Y$. It represents all potential outputs.
* **Image:** For a specific input $x \in X$, the assigned output $y = f(x) \in Y$ is called the **image of $x$ under $f$** (or the value of $f$ at $x$).
* **Pre-Image:** If $y = f(x)$, then $x$ is called a **pre-image of $y$**. An element $y \in Y$ can have zero, one, or multiple pre-images.
* **Range (Image of $X$):** The set of all actual outputs produced by $f$:
  $$\text{Range}(f) = \{y \in Y \mid \exists x \in X \text{ such that } y = f(x)\}$$
  * **Crucial Rule:** The range is always a subset of the co-domain: $\text{Range}(f) \subseteq \text{Co-domain}(f)$.

---

### Structural Rules for Arrow Diagrams (Directed Graphs)

In an arrow diagram representing a function $f: X \to Y$:
1. **Outgoing Arrows Rule:** Exactly **one** arrow must originate from **every** element in domain $X$. No element in $X$ can have zero arrows or multiple arrows leaving it.
2. **Incoming Arrows Rule:** Elements in target set $Y$ may have zero, one, or multiple incoming arrows.

---

### Concrete Exercise: Determining Function Ranges

Let $X = \{2, 4, 5\}$ and $Y = \{1, 2, 4, 6\}$. Determine the range for each of the following functions:

1. **Function $f: X \to Y$ given by assignments $f(2) = 6, \, f(4) = 1, \, f(5) = 6$:**
   * Outputs actually generated: $\{1, 6\}$.
   * $\text{Range}(f) = \{1, 6\}$.

2. **Function $g: X \to Y$ defined as $g = \{(2, 6), (4, 2), (5, 1)\}$:**
   * Extracting second components: $\{6, 2, 1\}$.
   * $\text{Range}(g) = \{1, 2, 6\}$.

3. **Function $h: X \to Y$ defined by $h(2) = 4, \, h(4) = 4, \, h(5) = 1$:**
   * Outputs generated: $\{4, 1\}$.
   * $\text{Range}(h) = \{1, 4\}$.

---

## 4. Graph of a Function & The Vertical Line Test

In Cartesian coordinate space, a function $f: \mathbb{R} \to \mathbb{R}$ can be plotted as a geometric graph consisting of points $(x, f(x))$.

### The Vertical Line Test

The geometric equivalent of the **Uniqueness Property** for functions on real numbers is known as the **Vertical Line Test**:

> **The Vertical Line Test:**
> A curve in the $xy$-plane represents the graph of a function $y = f(x)$ if and only if **no vertical line intersects the curve at more than one point**.

#### Comparison Walkthrough
* **Graph of $y = x^2$:** Any vertical line $x = c$ crosses the parabola $y = x^2$ at exactly one point $(c, c^2)$. Therefore, $y = x^2$ **is a valid function** ✅.
* **Graph of $x = y^2$ (or $y^2 = x$):** Solving for $y$ yields $y = \pm \sqrt{x}$. A vertical line at $x = 1$ intersects the graph at two distinct points: $(1, 1)$ and $(1, -1)$. Because $x = 1$ maps to two distinct outputs ($+1$ and $-1$), $x = y^2$ **fails the Vertical Line Test and is NOT a function** ❌.

---

## 5. Combinatorics: Counting Functions vs. Relations

A classic category of exam questions requires calculating the total possible number of relations and functions between two finite sets.

### Definitions & General Formulas

Let $X$ be a set with $m$ elements ($|X| = m$) and $Y$ be a set with $n$ elements ($|Y| = n$).

1. **Total Binary Relations:**
   * The Cartesian product $X \times Y$ contains $m \cdot n$ elements.
   * Any subset of $X \times Y$ is a relation. The number of subsets of a set with $k$ elements is $2^k$.
   * $$\text{Total Relations from } X \text{ to } Y = 2^{m \cdot n}$$

2. **Total Functions (Product Rule Derivation):**
   * For each element $x_1 \in X$, there are $n$ possible choices in $Y$ to assign as its image.
   * For $x_2 \in X$, there are $n$ choices in $Y$.
   * Applying the fundamental Product Rule of counting across all $m$ elements of $X$:
     $$\text{Total Functions } f: X \to Y = \underbrace{n \times n \times \dots \times n}_{m \text{ times}} = n^m$$
   * $$\text{Total Functions} = (\text{Size of Target Set})^{\text{Size of Domain Set}} = n^m$$

3. **Fraction of Relations that are Functions:**
   $$\text{Fraction} = \frac{\text{Total Functions}}{\text{Total Relations}} = \frac{n^m}{2^{m \cdot n}}$$

---

### Worked Numerical Example

Suppose set $X$ has $3$ elements ($m = 3$) and set $Y$ has $4$ elements ($n = 4$).

* **Total Binary Relations:**
  $$2^{m \cdot n} = 2^{3 \cdot 4} = 2^{12} = 4096 \text{ relations}$$
* **Total Functions:**
  $$n^m = 4^3 = 64 \text{ functions}$$
* **Fraction of Relations that are Functions:**
  $$\frac{64}{4096} = \frac{1}{64} \approx 1.56\%$$

---

### Special Category: Constant Functions

A function $f: X \to Y$ is called a **constant function** if every element in domain $X$ maps to the exact same element $c \in Y$:
$$\forall x \in X, \, f(x) = c \quad (\text{where } c \in Y \text{ is fixed})$$
* If $|Y| = n$, there are exactly **$n$ constant functions** from $X$ to $Y$.

---

## 6. Well-Definedness of Functions (Exam Problem Types)

In examination problems, a relation or formula $f: X \to Y$ is proposed, and you are asked to determine whether $f$ is **well-defined**.

> **Algebraic Criterion for Well-Definedness:**
> A function $f: X \to Y$ is well-defined if:
> $$\forall x_1, x_2 \in X, \quad x_1 = x_2 \implies f(x_1) = f(x_2)$$
> Equivalently, equal inputs in the domain must produce equal outputs in the co-domain, and every domain input must yield a valid, unambiguous result inside the co-domain.

---

### Four Classic Candidate Analyses ($\mathbb{Z} \to \mathbb{R}$)

Determine whether each proposed rule defines a valid function $f: \mathbb{Z} \to \mathbb{R}$:

1. **Rule: $f(n) = \pm n$**
   * **Analysis:** For $n = 3$, $f(3) = +3$ and $f(3) = -3$.
   * **Verdict:** **Not Well-Defined** ❌ (Fails uniqueness; $3$ maps to two distinct real numbers).

2. **Rule: $f(n) = \frac{1}{n^2 - 4}$**
   * **Analysis:** Setting $n^2 - 4 = 0$ gives $n = \pm 2$. For $n = 2 \in \mathbb{Z}$, $f(2) = \frac{1}{0}$, which is undefined in $\mathbb{R}$.
   * **Verdict:** **Not Well-Defined** ❌ (Fails everywhere defined; inputs $n = 2$ and $n = -2$ have no image).

3. **Rule: $f(n) = \sqrt{n}$**
   * **Analysis:** For negative integers like $n = -4 \in \mathbb{Z}$, $f(-4) = \sqrt{-4} = 2i \notin \mathbb{R}$.
   * **Verdict:** **Not Well-Defined** ❌ (Negative integers produce complex numbers outside the co-domain $\mathbb{R}$).

4. **Rule: $f(n) = \sqrt{n^2 + 1}$**
   * **Analysis:** For every integer $n \in \mathbb{Z}$, $n^2 \ge 0$, so $n^2 + 1 \ge 1 > 0$. The principal square root yields a unique, real number for every integer input.
   * **Verdict:** **Well-Defined Function** ✅.

---

### Classic Exam Counter-Example: Rational Equivalent Forms

> **Problem:** A student proposes a rule $h: \mathbb{Q} \to \mathbb{Q}$ defined by $h\left(\frac{m}{n}\right) = \frac{m^2}{n}$ for all $\frac{m}{n} \in \mathbb{Q}$. Is $h$ well-defined?

* **Proof of Invalidity (Counter-Example):**
  1. Consider the rational number $\frac{1}{2} \in \mathbb{Q}$.
     Applying the rule with $m = 1, n = 2$:
     $$h\left(\frac{1}{2}\right) = \frac{1^2}{2} = \frac{1}{2}$$
  2. Express the same rational number in an equivalent fraction form: $\frac{2}{4} \in \mathbb{Q}$ (since $\frac{1}{2} = \frac{2}{4}$).
     Applying the rule with $m = 2, n = 4$:
     $$h\left(\frac{2}{4}\right) = \frac{2^2}{4} = \frac{4}{4} = 1$$
  3. Compare the outputs:
     $$\frac{1}{2} = \frac{2}{4} \quad \text{but} \quad h\left(\frac{1}{2}\right) = \frac{1}{2} \neq 1 = h\left(\frac{2}{4}\right)$$
  4. Equal inputs yielded unequal outputs.
  * **Conclusion:** $h$ is **not well-defined** ❌.

---

### Step-by-Step Formal Proof of Well-Definedness

> **Problem:** Let $g: \mathbb{R} \to \mathbb{R}^+$ be defined by $g(x) = x^2 + 1$.
> 1. Prove that $g$ is well-defined.
> 2. Determine its Domain, Co-domain, and Range.

#### Part 1: Proof of Well-Definedness
* **Suppose:** Let $x_1, x_2 \in \mathbb{R}$ such that $x_1 = x_2$.
* **To Prove:** $g(x_1) = g(x_2)$.
* **Proof Steps:**
  1. Since $x_1 = x_2$, squaring both sides gives:
     $$x_1^2 = x_2^2$$
  2. Adding $1$ to both sides preserves equality:
     $$x_1^2 + 1 = x_2^2 + 1$$
  3. By definition of $g(x)$:
     $$g(x_1) = g(x_2)$$
* **Conclusion:** $g$ is a **well-defined function** $\blacksquare$.

#### Part 2: Sets Analysis
* **Domain:** $\mathbb{R}$ (Set of all real numbers).
* **Co-domain:** $\mathbb{R}^+$ (Set of positive real numbers).
* **Range:** For all $x \in \mathbb{R}$, $x^2 \ge 0 \implies x^2 + 1 \ge 1$.
  $$\text{Range}(g) = [1, \infty) = \{y \in \mathbb{R} \mid y \ge 1\}$$

---

## 7. Binary and Unary Operations as Functions

Many operations across arithmetic, set theory, and digital logic are formal functions.

### 1. Binary Operations ($\ast: A \times A \to A$)

A **binary operation** $\ast$ on a set $A$ is a function that assigns to every ordered pair $(a, b) \in A \times A$ a unique element $c \in A$:
$$\ast: A \times A \to A \quad \text{where } \ast(a, b) = a \ast b = c \in A$$

* **Closure Property:** For $\ast$ to be a valid binary operation on set $A$, $a \ast b$ must belong to set $A$ for all $a, b \in A$.
  * **Addition ($+$) and Multiplication ($\times$) on $\mathbb{N}$:** Valid binary operations because $\forall a, b \in \mathbb{N}, (a + b) \in \mathbb{N}$ and $(a \cdot b) \in \mathbb{N}$.
  * **Subtraction ($-$) on $\mathbb{N}$:** **Not a binary operation** on $\mathbb{N}$ because $2, 3 \in \mathbb{N}$ but $2 - 3 = -1 \notin \mathbb{N}$ (fails closure). However, subtraction **is** a valid binary operation on $\mathbb{Z}$.
  * **Division ($\div$) on Non-Zero Rationals $\mathbb{Q}^*$:** Valid binary operation because dividing two non-zero rationals yields a non-zero rational.
  * **Set Operations ($\cup, \cap, \setminus$):** Binary operations on the Power Set $\mathcal{P}(A)$:
    $$\cup: \mathcal{P}(A) \times \mathcal{P}(A) \to \mathcal{P}(A)$$
  * **Logical Connectives ($\land, \lor, \to, \leftrightarrow$) & Logic Gates (AND, OR, XOR):** Binary operations on boolean set $\{T, F\}$ or digital set $\{0, 1\}$:
    $$\text{AND}: \{0, 1\} \times \{0, 1\} \to \{0, 1\}$$

### 2. Unary Operations ($f: A \to A$)

A **unary operation** on a set $A$ is a function taking a single input from $A$ and returning an output in $A$:
$$f: A \to A$$
* **Logical Negation ($\sim$) / NOT Gate:** A unary operation on $\{T, F\}$ or $\{0, 1\}$:
  $$\text{NOT}(0) = 1, \quad \text{NOT}(1) = 0$$

---

## 8. Exam Quick-Reference Comparison Matrix

| Concept | Domain Input | Target Output | Key Defining Condition |
| :--- | :--- | :--- | :--- |
| **Binary Relation $R$** | Elements from $X$ | Elements in $Y$ | Any arbitrary subset $R \subseteq X \times Y$. |
| **Function $f: X \to Y$** | Every element in $X$ | Unique element in $Y$ | Every $x \in X$ maps to **exactly one** $y \in Y$. |
| **Binary Operation $\ast$** | Pairs $(a, b) \in A \times A$ | Single element in $A$ | Function $\ast: A \times A \to A$ satisfying closure. |
| **Unary Operation** | Single element $a \in A$ | Single element in $A$ | Function $f: A \to A$ (e.g., Logical NOT). |
