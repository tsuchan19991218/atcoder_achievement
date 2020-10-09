var n = Int(readLine()!)!
var flag: Bool = false

for ans in 1...n{
    if Int(Double(ans) * 1.08) == n{
        flag = true
        print(ans)
        break
    }
}
if !flag{
    print(":(")
}
