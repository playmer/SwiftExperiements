let JoshTest : @convention(c) (Int32, Int32) -> Int32 = {
    (x, y) -> Int32 in
    return x + y
} 

@_silgen_name("JoshTestWithFeeling")
func Blah(a : Int32, b : Int32) -> Int32
{
  return a + b;
}
