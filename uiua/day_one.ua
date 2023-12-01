Data ← &fras "../data/day_one.txt"
TempData ← "two1nine\neightwothree\nabcone2threexyz\nxtwone3four\n4nineeightseven2\nzoneight234\n7pqrstsixteen"

# part one
PartOne ← /+≡(parse [⊃⊢(⊢ ⇌) ⊏ :∵⊔: ⊚ <@a .]) ⊜□≠ @\n .
PartOne Data

# part two

ParseOne ← (∘|"o1e";) /↧ ⬚@\0= "one" .
ParseTwo ← (∘|"t2o";) /↧ ⬚@\0= "two" .
ParseThree ← (∘|"t3e";) /↧ ⬚@\0= "three" .
ParseFour ← (∘|"f4r";) /↧ ⬚@\0= "four" .
ParseFive ← (∘|"f5e";) /↧ ⬚@\0= "five" .
ParseSix ← (∘|"s6x";) /↧ ⬚@\0= "six" .
ParseSeven ← (∘|"s7n";) /↧ ⬚@\0= "seven" .
ParseEight ← (∘|"e8t";) /↧ ⬚@\0= "eight" .
ParseNine ← (∘|"n9e";) /↧ ⬚@\0= "nine" .
ParseZero ← (∘|"z0o";) /↧ ⬚@\0= "zero" .
ParseNum ← ParseOne ParseTwo ParseThree ParseFour ParseFive ParseSix ParseSeven ParseEight ParseNine ParseZero

Parse ← ⍢(: ⊂ ⊙(⊂ :) ⊙⊙ParseNum ⊙⊙. : ⊃(↘ + ⊙: ⊙⊙⧻)↙⊢ ⊚ ⌕ ⊙. ⊙:⊙⊙:..)(≠ 0 /+ ⌕)
PartOne ; Parse "one" ; Parse "two" ; Parse "three" ; Parse "four" ; Parse "five" ; Parse "six" ; Parse "seven" ; Parse "eight" ; Parse "nine" ; Parse "zero" Data
