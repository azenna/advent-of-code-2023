d ← •file.Lines "../data/day_two.txt"

Part ← (⊢-˜¬×+`)∘=⊔⊢

Num ← {⊑(𝕩 ⍷ '0'+↕10) / ↕10}
ArrNum ← +´(⌽ (⋆⟜↕˜10)⥊˜≢)⊸×
Count ← {1 ↑ ArrNum¨ Num¨¨ ¯1 ↓¨ ∾´∘(𝕨∊¨⊢)⊸/𝕩}
CountRGB ← ('r'Count⊢)∾('g'Count⊢)∾('b'Count⊢)
Format ← ∾´((1⊏⊣)∾(0⊑2⊑⊢))∘(⍋⊸⊏3↑⊢)
Parts ← ((Format ' 'Part⊢)¨ ','Part⊢)¨ ';'Part⊢

x ← +´1+/0=(+´0>[12,13,14]-⌈´)¨CountRGB¨¨Parts¨(⊑≢"Game X: ")↓¨d
•Show x

y ← +´ ×´¨ ⌈´¨ CountRGB¨¨Parts¨(⊑≢"Game X: ")↓¨d
•Show y
