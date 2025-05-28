# 🧮 Understanding Float (IEEE-754)

## What is a Float?
A **float** is a way for computers to store decimal numbers (e.g., `3.14`, `-0.0001`) using the IEEE-754 standard.

A 32-bit (single-precision) float is made up of:
- **Sign bit (1 bit)** — whether the number is positive or negative
- **Exponent (8 bits)** — the scale (how big or small)
- **Mantissa (23 bits)** — the significant digits

---

## 🔢 How is the Value Calculated?
The formula: value = mantissa × 2^exponent
But it's all in **binary**, so powers of 2 are used instead of 10.

---

## 🕵️ Why Not Store the Same Number in Different Ways?
Example (in decimal):2 × 10⁻¹ = 0.2 × 10⁰ = 0.02 × 10¹

Allowing this in binary would:
- Waste memory
- Make calculations harder

---

## 💡 Smart Fix: The Hidden “1”
To save space:
- Floats **assume** a leading `1.` in the mantissa (like `1.010101...`)
- This is called **"1.m" format**
- The `1` is **not stored** — it's **implied**

---

## ❓ What About Zero?
You can't assume a 1 for zero! So:
- **Zero is a special case**: all bits (sign, exponent, mantissa) are 0

---

## ⚙️ Exponent Biasing
Exponents are stored with a **bias of 127**:
- To store exponent `0`, save `127` (i.e., `0x7F`)
- Exponent `-1` → store `126`
- Exponent `1` → store `128`

This lets floats represent both **large** and **small** numbers.

---

## 🧠 Final Thought
- The smallest exponent you can store is actually `-126`, not `-127`
- This is a trade-off so we can **accurately store values like 0 and 1**


## 🔍 Float Equality
- Using `==` with floats is unreliable due to tiny rounding errors.
- Instead, check if two floats are *“close enough”* using a small difference (called `EPSILON`), but this isn’t always reliable for very large or small values.
- Better float comparison should consider the number of **significant digits**, not just absolute difference.

---

## ⚠️ Float Overflow
- Floats can represent numbers too big for regular integers.
- When overflow happens, floats give `+inf` or `-inf`, which are helpful to detect errors.
- Be cautious when converting between floats and integers—large integers may lose precision in a float.
- Example: a float has ~7 decimal digits of precision; a 32-bit int can need up to 9.

---

## 🔻 Loss of Precision
- Subtracting two nearly equal floats can cause **loss of significance** (digits cancel out).
- Adding small numbers to large ones can cause the small ones to be ignored.
- Rearranging calculations (e.g., factor out large terms) can avoid overflow or precision loss.

---

## 📏 Rule of Thumb
- More operations on a float = more chance of inaccuracy.
- Avoid reusing float results too often (“feedback” loops).
- Prefer using **stable formulas** or even **integers** (like storing fractions as numerator/denominator).

# 🧮 Fixed Point Numbers – Quick Summary

**Fixed point numbers** represent fractional values using integers by fixing the position of the binary (fractional) point.

## 🔧 How It Works
- Format: `fixed<w, b>` → `w` total bits, `b` fractional bits.
- Example: `fixed<8,3>` → 5 bits integer, 3 bits fraction.
- Uses integer arithmetic with implicit scaling.
- Bit shifts adjust value: left = ×2, right = ÷2.

## ➕ Pros
- 🚀 Fast: Uses integer math (great for DSP, games).
- 🧰 Simple: No special hardware needed.

## ➖ Cons
- 🎯 Limited precision/range (trade-off between them).
- ❌ No native support in C (but easy to implement).

## ➖ Negative Values
- Use **2’s complement**, same as integers.
- All arithmetic operations still work (add, subtract, shift).

## ✅ Summary
Fixed point = fast & efficient real number handling using integer operations. Ideal when **performance > precision**.
