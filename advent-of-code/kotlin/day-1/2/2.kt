import java.io.File

val INPUT = File("../input").readLines()

fun fuelForComponent(weight: Int): Int {
  val fuel = weight / 3 - 2
  if (fuel <= 0) {
    return 0
  } else {
    return fuel + fuelForComponent(fuel)
  }
}

fun main(args: Array<String>) {
  println(INPUT.map{it.toInt()}.map { fuelForComponent(it) }.sum())
}
