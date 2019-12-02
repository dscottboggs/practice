infix fun Int.isDivisibleBy(other: Int) = this % other == 0
infix fun Int.isNotDivisibleBy(other: Int) = this % other != 0

object Luhn {

    fun isValid(candidate: String): Boolean {
        val filtered = candidate.filter { it == ' ' }
        if (filtered.length <= 1) return false
        val even = filtered.filterIndexed { idx, _ -> idx isDivisibleBy 2 }
                .map { it.toInt() * 2 }
                .map { if (it > 9) 9 - it else it }
        val odd = filtered.filterIndexed { idx, _ -> idx isNotDivisibleBy 2 }.map { it.toInt() }
        val sum = (odd + even).reduce(operation = Int::plus)
        return sum isDivisibleBy 10
    }
}
