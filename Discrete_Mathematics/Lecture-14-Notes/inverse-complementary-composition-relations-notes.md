# MTH202 Lecture 14 Notes: Inverse, Complementary, and Composition of Relations

This study guide provides a comprehensive, exam-oriented reference for the foundational relational operations introduced in Lecture 14 of MTH202 Discrete Mathematics. It covers the **Inverse of a Relation**, **Complementary Relations**, and **Composition of Relations**, complete with formal definitions, symbolic proofs, matrix and graphical representations, and step-by-step numerical examples.

---

## 1. Inverse of a Relation ($R^{-1}$) and Related Concepts

The inverse of a relation is formed by reversing the direction of association for every ordered pair in the original relation.

### 1.1 Formal Definition and Symbolic Rule

> **Definition (Inverse Relation):** Let $R$ be a binary relation from set $A$ to set $B$ (i.e., $R \subseteq A \times B$). The **inverse relation** of $R$, denoted as $R^{-1}$, is a relation from set $B$ to set $A$ defined as:
> $$R^{-1} = \{(b, a) \in B \times A \mid (a, b) \in R\}$$

* **Operational Rule:** To construct $R^{-1}$, interchange (swap) the first and second elements of every ordered pair $(a, b) \in R$.
* **Domain and Range Swap:** The domain of $R^{-1}$ is equal to the range of $R$, and the range of $R^{-1}$ is equal to the domain of $R$:
  $$\text{Dom}(R^{-1}) = \text{Ran}(R) \quad \text{and} \quad \text{Ran}(R^{-1}) = \text{Dom}(R)$$

### 1.2 Lecture 14 Concrete Numerical Example

Let set $A = \{2, 3, 4\}$ and set $B = \{2, 6, 8\}$. Define relation $R$ from $A$ to $B$ as the **"divides"** relation ($a \, R \, b \iff a \mid b$):

$$R = \{(2, 2), (2, 6), (2, 8), (3, 6), (4, 8)\}$$

To construct the inverse relation $R^{-1}$, reverse each ordered pair:

$$R^{-1} = \{(2, 2), (6, 2), (8, 2), (6, 3), (8, 4)\}$$

* **Conceptual Transformation:** While $R$ expresses the relation *"is a divisor of"* ($a \mid b$), its inverse $R^{-1}$ expresses the relation *"is a multiple of"* ($b$ is a multiple of $a$). For instance, $(6, 2) \in R^{-1}$ because $6$ is a multiple of $2$.

### 1.3 Graphical and Matrix Representations

Inverse relations exhibit clear geometric and algebraic symmetries across standard representations:

* **Arrow Diagram (Directed Graph):**
  * The set vertices for $A$ and $B$ remain fixed.
  * The direction of every arrow is reversed. If an arrow points from $a \in A$ to $b \in B$ in $R$, the corresponding arrow points from $b \in B$ to $a \in A$ in $R^{-1}$.
* **Relation Matrix ($M_{R^{-1}}$):**
  * The Boolean matrix of $R^{-1}$ is the **transpose** of the Boolean matrix of $R$:
    $$M_{R^{-1}} = M_R^T$$
  * Rows and columns are swapped. An entry $m_{ij} = 1$ in $M_R$ becomes $m_{ji} = 1$ in $M_{R^{-1}}$.

For the example above, the relation matrix $M_R$ and its transpose $M_{R^{-1}}$ are:

$$M_R = \begin{pmatrix} 1 & 1 & 1 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix} \implies M_{R^{-1}} = M_R^T = \begin{pmatrix} 1 & 0 & 0 \\ 1 & 1 & 0 \\ 1 & 0 & 1 \end{pmatrix}$$

### 1.4 Preservation of Relational Properties

A fundamental property established in Lecture 14 is that $R^{-1}$ inherits all core structural properties from $R$ without alteration:

1. **Reflexivity:** If $R$ is reflexive on set $A$, then $R^{-1}$ is **reflexive** on $A$.
   * *Proof Intuition:* For all $a \in A$, $(a, a) \in R$. Swapping $(a, a)$ yields $(a, a) \in R^{-1}$.
2. **Symmetry:** If $R$ is symmetric on set $A$, then $R^{-1}$ is **symmetric** on $A$.
   * *Proof Intuition:* $(a, b) \in R^{-1} \implies (b, a) \in R \implies (a, b) \in R \implies (b, a) \in R^{-1}$.
3. **Transitivity:** If $R$ is transitive on set $A$, then $R^{-1}$ is **transitive** on $A$.
   * *Proof Intuition:* $(a, b), (b, c) \in R^{-1} \implies (c, b), (b, a) \in R \implies (c, a) \in R \implies (a, c) \in R^{-1}$.
4. **Antisymmetry:** If $R$ is antisymmetric on set $A$, then $R^{-1}$ is **antisymmetric** on $A$.
   * *Proof Intuition:* $(a, b), (b, a) \in R^{-1} \implies (b, a), (a, b) \in R \implies a = b$.

### 1.5 The Symmetry Theorem ($R = R^{-1}$) and Proof Analysis

> **Theorem:** A binary relation $R$ defined on a set $A$ is **symmetric** if and only if:
> $$R = R^{-1}$$

To prove set equality $R = R^{-1}$, formal logic requires demonstrating two directional inclusions: $R^{-1} \subseteq R$ and $R \subseteq R^{-1}$.

#### Detailed Step-by-Step Breakdown of both Subset Inclusions:

1. **Proving $R^{-1} \subseteq R$:**
   * Assume $(x, y) \in R^{-1}$ is an arbitrary pair in $R^{-1}$.
   * By definition of inverse, $(x, y) \in R^{-1} \implies (y, x) \in R$.
   * Since $R$ is given to be **symmetric**, $(y, x) \in R \implies (x, y) \in R$.
   * Therefore, every element in $R^{-1}$ belongs to $R$, establishing $R^{-1} \subseteq R$.

2. **Proving $R \subseteq R^{-1}$:**
   * Assume $(a, b) \in R$ is an arbitrary pair in the original relation $R$.
   * Since $R$ is given to be **symmetric**, $(a, b) \in R \implies (b, a) \in R$.
   * By definition of inverse, if $(b, a) \in R$, then swapping its elements places $(a, b) \in R^{-1}$.
   * Therefore, every element in $R$ belongs to $R^{-1}$, establishing $R \subseteq R^{-1}$.

* **Conclusion:** Since $R^{-1} \subseteq R$ and $R \subseteq R^{-1}$, it follows that $R = R^{-1}$.

---

## 2. Complementary Relation ($\bar{R}$ or $R^c$) and Related Concepts

The complementary relation contains all ordered pairs from the universal Cartesian product that are absent from the original relation.

### 2.1 Formal Definition and Formula

> **Definition (Complementary Relation):** Let $R$ be a binary relation from set $A$ to set $B$. The **complementary relation** of $R$, denoted as $\bar{R}$ or $R^c$, is defined as:
> $$\bar{R} = (A \times B) - R = \{(a, b) \in A \times B \mid (a, b) \notin R\}$$

* **Operational Rule:** To construct $\bar{R}$, list all possible ordered pairs in the Cartesian product $A \times B$, then remove all pairs present in $R$.

### 2.2 Concrete Numerical Example

Let set $A = \{1, 2, 3\}$. The total universal relation $A \times A$ contains $3 \times 3 = 9$ ordered pairs:

$$A \times A = \{(1, 1), (1, 2), (1, 3), (2, 1), (2, 2), (2, 3), (3, 1), (3, 2), (3, 3)\}$$

Suppose relation $R$ on set $A$ is given as:

$$R = \{(1, 1), (1, 3), (2, 2), (2, 3), (3, 1)\}$$

To construct the complementary relation $\bar{R}$, collect all pairs in $A \times A$ missing from $R$:

$$\bar{R} = \{(1, 2), (2, 1), (3, 2), (3, 3)\}$$

### 2.3 Real-World Mathematical Example

Consider relations on the set of integers $\mathbb{Z}$:
* If relation $R$ is defined as **"strictly less than"** ($a \, R \, b \iff a < b$):
  $$R = \{(a, b) \in \mathbb{Z} \times \mathbb{Z} \mid a < b\}$$
* The complementary relation $\bar{R}$ consists of all pairs where $a < b$ is false, which means $a \ge b$:
  $$\bar{R} = \{(a, b) \in \mathbb{Z} \times \mathbb{Z} \mid a \ge b\}$$
  *(The complement of "strictly less than" is "greater than or equal to")*.

### 2.4 Structural Properties and Numerical Proof Walkthroughs

Lecture 14 establishes two fundamental equivalence theorems for complementary relations.

#### Theorem 1: $R$ is Reflexive $\iff \bar{R}$ is Irreflexive

* **Reflexive Condition:** $R$ contains every self-pair $(a, a)$ for all $a \in A$.
* **Irreflexive Condition:** $\bar{R}$ contains no self-pair $(a, a)$ for any $a \in A$.

##### Numerical Walkthrough:
1. Let $A = \{1, 2, 3\}$.
2. Construct a reflexive relation $R = \{(1, 1), (2, 2), (3, 3), (1, 2)\}$.
3. Compute $\bar{R} = (A \times A) - R = \{(1, 3), (2, 1), (2, 3), (3, 1), (3, 2)\}$.
4. Check $\bar{R}$ for self-pairs: $(1, 1) \notin \bar{R}$, $(2, 2) \notin \bar{R}$, $(3, 3) \notin \bar{R}$.
5. Since $R$ pulled every self-pair into itself, zero self-pairs remain in $\bar{R}$, making $\bar{R}$ **irreflexive**.

#### Theorem 2: $R$ is Symmetric $\iff \bar{R}$ is Symmetric

* **Symmetric Condition:** Whenever $(a, b) \in R$, its reverse pair $(b, a) \in R$.

##### Numerical Walkthrough:
1. Let $A = \{1, 2, 3\}$.
2. Construct a symmetric relation $R = \{(1, 1), (1, 2), (2, 1), (2, 3), (3, 2)\}$.
3. Compute $\bar{R} = (A \times A) - R = \{(2, 2), (3, 3), (1, 3), (3, 1)\}$.
4. Check $\bar{R}$ for symmetry: $(1, 3) \in \bar{R}$ and its reverse $(3, 1) \in \bar{R}$; self-pairs $(2, 2)$ and $(3, 3)$ are symmetric.
5. Because every missing pair in $R$ was missing in both directions, its complement $\bar{R}$ is **symmetric**.

---

## 3. Composition of Relations ($S \circ R$)

Composition connects elements across sets through a two-step relational chain or bridge.

### 3.1 Core Concept and Plain English Rule

If relation $R$ relates elements from set $A$ to set $B$, and relation $S$ relates elements from set $B$ to set $C$, then the composite relation $S \circ R$ relates elements from set $A$ directly to set $C$:

$$\text{Set } A \xrightarrow{\quad R \quad} \text{Set } B \xrightarrow{\quad S \quad} \text{Set } C \implies \text{Set } A \xrightarrow{\quad S \circ R \quad} \text{Set } C$$

> **Exam Order Warning:** Although relation $R$ is applied first and relation $S$ second, the composite relation is written as $S \circ R$ (read as "$S$ circle $R$" or "$S$ composed with $R$"). $R$ is placed on the right because it acts first on input elements from set $A$.

### 3.2 Formal Symbolic Formula

> **Definition (Composition of Relations):** Let $R \subseteq A \times B$ and $S \subseteq B \times C$. The **composite relation** $S \circ R \subseteq A \times C$ is defined as:
> $$S \circ R = \{(a, c) \in A \times C \mid \exists b \in B \text{ such that } (a, b) \in R \land (b, c) \in S\}$$

* **Bridge Rule:** A pair $(a, c)$ belongs to $S \circ R$ if and only if there exists at least one middle element $b \in B$ serving as a transitional link where $a \, R \, b$ and $b \, S \, c$.

### 3.3 Concrete Numerical Example (Lecture 14)

Define three sets:
* Set $A = \{a, b, c\}$
* Set $B = \{1, 2, 3, 4\}$ *(The middle set)*
* Set $C = \{x, y, z\}$

Let relations $R \subseteq A \times B$ and $S \subseteq B \times C$ be given as:
* $R = \{(a, 1), (a, 4), (b, 3), (c, 1)\}$
* $S = \{(1, x), (2, x), (3, y), (3, z)\}$

#### Step-by-Step Chain Tracing for $S \circ R$:

1. **Test element $a \in A$:**
   * $(a, 1) \in R$ and $(1, x) \in S \implies (a, x) \in S \circ R$.
   * $(a, 4) \in R$, but $4$ connects to no element in $S$ (dead end).
2. **Test element $b \in A$:**
   * $(b, 3) \in R$ and $(3, y) \in S \implies (b, y) \in S \circ R$.
   * $(b, 3) \in R$ and $(3, z) \in S \implies (b, z) \in S \circ R$.
3. **Test element $c \in A$:**
   * $(c, 1) \in R$ and $(1, x) \in S \implies (c, x) \in S \circ R$.

#### Resulting Composite Relation:

$$S \circ R = \{(a, x), (b, y), (b, z), (c, x)\}$$

### 3.4 Matrix Representation: Boolean Matrix Product

The relation matrix of a composite relation is evaluated using the **Boolean matrix product** of the constituent matrices:

$$M_{S \circ R} = M_R \odot M_S$$

In Boolean matrix multiplication ($\odot$), standard addition is replaced by logical disjunction ($\lor$, where $1 + 1 = 1$), and standard multiplication is replaced by logical conjunction ($\land$):

* **Boolean Arithmetic Rules:**
  * $0 + 0 = 0, \quad 0 + 1 = 1, \quad 1 + 1 = 1$
  * $0 \cdot 0 = 0, \quad 0 \cdot 1 = 0, \quad 1 \cdot 1 = 1$

### 3.5 Algebraic and Structural Properties

1. **Non-Commutativity:** In general, relation composition is **non-commutative**:
   $$S \circ R \neq R \circ S$$
   *(The sets $A$ and $C$ may have different dimensions, or the backward chain $R \circ S$ may be completely undefined).*
2. **Preservation of Reflexivity:** If $R$ and $S$ are both reflexive binary relations on set $A$, then their composition $S \circ R$ is **reflexive** on $A$.
3. **Associativity:** Composition of relations is associative across three relations $R, S, T$:
   $$T \circ (S \circ R) = (T \circ S) \circ R$$

---

## 4. Exam Quick-Reference Summary & Comparison Matrix

| Relational Operation | Formal Definition | Matrix / Visual Representation | Key Property Preservation & Theorems | Exam Pitfalls to Avoid |
| :--- | :--- | :--- | :--- | :--- |
| **Inverse Relation ($R^{-1}$)** | $R^{-1} = \{(b, a) \mid (a, b) \in R\}$ | Transpose of relation matrix: $M_{R^{-1}} = M_R^T$. Arrow directions reversed. | Preserves Reflexive, Symmetric, Transitive, and Antisymmetric properties. <br> **Theorem:** $R$ symmetric $\iff R = R^{-1}$. | Do not confuse swapping elements $(b, a)$ with negating or removing pairs. |
| **Complementary Relation ($\bar{R}$)** | $\bar{R} = (A \times B) - R$ | Matrix entries flipped ($0 \to 1, 1 \to 0$). All missing pairs included. | **Theorem 1:** $R$ reflexive $\iff \bar{R}$ irreflexive. <br> **Theorem 2:** $R$ symmetric $\iff \bar{R}$ symmetric. | Remember $\bar{R}$ is defined relative to the full $A \times B$, not just $R$. |
| **Composition ($S \circ R$)** | $S \circ R = \{(a, c) \mid \exists b, \, (a, b) \in R \land (b, c) \in S\}$ | Boolean Matrix Product: $M_{S \circ R} = M_R \odot M_S$. Two-step arrow paths. | Preserves Reflexivity (if both $R, S$ reflexive). Associative, but **non-commutative**. | **Order Pitfall:** $R$ executes first, $S$ second, but is written as $S \circ R$. |

### Summary Checklist for Exam Review

* [x] **Inverse Swap:** $(a, b) \in R \implies (b, a) \in R^{-1}$.
* [x] **Symmetry Condition:** $R = R^{-1}$ requires proving both $R \subseteq R^{-1}$ and $R^{-1} \subseteq R$.
* [x] **Complement Formula:** $\bar{R} = (A \times B) - R$.
* [x] **Reflexive Complement:** $R$ reflexive $\iff \bar{R}$ irreflexive.
* [x] **Composition Chain:** $(a, b) \in R$ and $(b, c) \in S \implies (a, c) \in S \circ R$.
* [x] **Matrix Composition:** Use Boolean addition ($1 + 1 = 1$) for $M_R \odot M_S$.
