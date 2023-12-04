d ← •file.Lines "../data/day_one.txt"
t ← ⟨"hello1", "world2"⟩

nss ← "zero"‿"one"‿"two"‿"three"‿"four"‿"five"‿"six"‿"seven"‿"eight"‿"nine"
nis ← ⋈¨'0'+↕10
ns ← nss∾nis


#Parsing
N ← {(𝕩 ⍷ "0123456789") / ↕10}
A ← {+´10‿1×⥊N¨0‿¯1⊏𝕩}

#Part one
x ← +´A¨(/¨d<'a')⊏¨d
•Show x

#Part two
Nums ← {
  b ← /¨ ns ⍷¨ <𝕩
  ∾´ (⍋∾´b) ⊏ ((∾´≢¨ b) / ↕1⊣´≢b) ⊏ ∾˜nis
}
y ← +´A¨Nums¨d
•Show y
