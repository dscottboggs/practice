

fun get_results(alice: Array<Int>, bob: Array<Int>): Array<Int>{
    var ascore = 0
    var bscore = 0
    var aliceScores = { ascore++ }
    var bobScores = { bscore++ }
    alice.forEachIndexed({i: Int, aliceVal: Int -> {
        when {
        aliceVal > bob[i] -> aliceScores()
        aliceVal < bob[i] -> bobScores()
        else -> null
        }
    }})
    return arrayOf(ascore, bscore)
}
