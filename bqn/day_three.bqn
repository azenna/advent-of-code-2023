d ← •file.Lines "../data/day_three.txt"

cols ← ↕140
n ← '0'+↕10
P0 ← ((⊢-˜¬×+`)0=⊢)⊸⊔
ns ← ∾ cols ⋈¨¨¨ (1-˜(((⊢-˜¬×+`)0=⊢)⊸⊔(1+cols)×(+´n⍷¨<)))¨d 
ss ← ∾´cols⋈¨¨/¨¬∘(+´(n∾".")⍷¨<)¨d
touching ← (+´{2>√+´¨2⋆˜(|𝕩-⊢)¨∾ns}¨ss)/∾ns
Ix ← {(¯1⊑𝕩)⊑(0⊑𝕩)⊑d}
Num ← {⊑(𝕩 ⍷ '0'+↕10) / ↕10}
ArrNum ← +´(⌽ (⋆⟜↕˜10)⥊˜≢)⊸×

•Show ns
•Show +´ ArrNum¨ (Num Ix)¨¨ (×+´{(∨´((∧´𝕩=⊢)¨⊢))¨ns}¨touching)/ns
