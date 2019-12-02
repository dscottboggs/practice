import java.io.File

val INPUT = File("../input").readLines()

fun main(args: Array<String>) {
  val fuel = INPUT.map { it.toInt() / 3 - 2 }.sum()
  println(fuel)
}
