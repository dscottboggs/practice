// can't seem to import any of these.
import junit.framework.*;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;


public class test_LinkedList {  // Test Runner
    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(
            TestSLLNode.class
        );

        for (Failure failure : result.getFailures() ) {
            System.out.println(failure.toString());
        }
        System.out.println(result.wasSuccessful());
    }
}

private class TestSLLNode extends TestCase {
    protected SLLNode testNode1;
    protected SLLNode testNode2;
    protected int testData1 = 1;
    protected int testData2 = 2;
    protected void tearDown(){
        testNode11 = testNode2 = null;
    }
    public void testConstructorWithNoTail(){
        // Test the single-argument constructor.
        testNode1 = new SLLNode(testData1);
        assertEqual (testNode1.data, testData1);
        assertNull  (testNode1.next);
    }
    public void testConstructorWithTail(){
        // test the two-argument constructor;
        testNode2 = new SLLNode(testData2);
        testNode1 = new SLLNode(testData1, testNode2);
        assertEqual     (testNode1.data, testData1);
        assertNotNull   (testNode1.next);
        assertEqual     (testNode1.next.data, testData2);
        assertSame      (testNode1.next, testNode2);
        assertEqual     (testNode2.data, testData2);
        assertNull      (testNode2.next);
    }
}
