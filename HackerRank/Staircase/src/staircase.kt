
class Staircase(val size: Int){
    fun build(){
        for (row in 0..size-1){
            for (col in 0..size-1){
                if (col<size-row-1){
                    print(' ')
                } else {
                    print('#')
                }
            }
            println()
        }
    }
}

fun checkStringValidity(str: String?): Boolean {
  if (str is String){
    if (str.length > 0){
      return true
    } else {
      return false
    }
  } else {
    return false
  }
}

fun main(args: Array<String>){
    var size: Int
    var input: String?
    if (args.size == 1) {
      input = args[0]
    } else {
      print("Size of staircase: ")
      input = readLine()
    }
    if (checkStringValidity(input)) {
      size = input!!.toInt()
    } else {
      throw IllegalArgumentException("Input cannot be converted to an int!")
    }
    Staircase(size).build()
}
