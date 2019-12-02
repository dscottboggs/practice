
aliceTriplet = ()
bobTriplet = ()

def get_triplet(which):
    returnTriplet = []
    for val in range(3):
        returnTriplet.append(int(input("%s Triplet item %d: " % (which, val+1))))
    return returnTriplet

aliceTriplet = get_triplet("alice")
bobTriplet = get_triplet("bob")

def get_results(alice: list, bob: list):
    ascore, bscore = 0, 0
    for aliceVal, bobVal in zip(alice, bob):
        assert 1 <= aliceVal <= 100,\
            "Alice's answer should have been between 1 and 100, inclusive, but it was %d" % aliceVal
        assert 1 <= bobVal <= 100,\
            "Bob's answer should have been between 1 and 100, inclusive, but it was %d" % bobVal
        if aliceVal > bobVal:
            ascore+=1
        if aliceVal < bobVal:
            bscore+=1
    return ascore, bscore

aliceScore, bobScore = get_results(aliceTriplet, bobTriplet)
print(aliceScore, bobScore)
