import java.util.Map;
import junit.framework.*;

public class experiment {
    public static void main(String[] args) {
        Map<String, String> environment = System.getenv();
        experiment.printEnvironmentVariables(environment);
        System.out.print("print newline:\n");
        System.out.format("format backslash newline: \npercent newline: %n");
    }

    private static void printEnvironmentVariables(
        Map<String, String> environment
    ){
        for( String key : environment.keySet() ){
            System.out.format("%s=%s%n", key, environment.get(key));
        }
    }
}
