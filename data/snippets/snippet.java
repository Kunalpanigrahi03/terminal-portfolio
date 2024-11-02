import java.lang.annotation.*;
import java.lang.reflect.*;

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@interface Test {
    String info() default "Running test";
}

public class snippet {
    @Test(info = "Test case 1")
    public void test1() {
        System.out.println("Executing test 1");
    }

    @Test(info = "Test case 2")
    public void test2() {
        System.out.println("Executing test 2");
    }

    public static void main(String[] args) throws Exception {
        snippet suite = new snippet();
        for (Method method : suite.getClass().getDeclaredMethods()) {
            if (method.isAnnotationPresent(Test.class)) {
                Test test = method.getAnnotation(Test.class);
                System.out.println("Info: " + test.info());
                method.invoke(suite);
            }
        }
    }
}
