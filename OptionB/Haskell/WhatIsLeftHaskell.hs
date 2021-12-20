evenRemover :: [a] -> [a]
evenRemover lst = map fst $ filter (even.snd) indexed where
    indexed = zip lst [0..]
    
oddRemover :: [a] -> [a]
oddRemover lst = map fst $ filter (odd.snd) indexed where
    indexed = zip lst [0..]
    
threeRemover :: [a] -> [a]
threeRemover lst = map fst $ filter (\(_, i) -> (i+1) `mod` 3 /= (0 :: Int)) indexed where
    indexed = zip lst [0..]
    
fLeft :: Int -> [a] -> [a]
fLeft n arr | (length arr == 1) = arr
            | (n `mod` 3 == 1) = fLeft (n+1) (evenRemover(arr))
            | (n `mod` 3 == 2) = fLeft (n+1) (oddRemover(arr))
            | (n `mod` 3 == 0) = fLeft (n+1) (threeRemover(arr))

main=do
    input <- getLine
    let n = (read input :: Int)
    let arr = [1..n]
    let ans = fLeft 1 arr
    print(ans!!0)