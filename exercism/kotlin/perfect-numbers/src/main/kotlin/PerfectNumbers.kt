
enum class Classification {
    DEFICIENT, PERFECT, ABUNDANT;
    companion object {
        fun classify(num: Int): Classification {
            if (num <= 0) {
                throw RuntimeException("Cannot classify a negative number or zero")
            } else {
                val nic = factors(of = num).sum()
                return when {
                    nic > num -> ABUNDANT
                    nic < num -> DEFICIENT
                    else -> PERFECT
                }
            }
        }
    }
}

fun classify(naturalNumber: Int): Classification {
    return Classification.classify(naturalNumber)
}

private fun factors(of: Int): List<Int> {
    return (1..of).filter { x -> (of % x == 0) and (of != x) }
}
