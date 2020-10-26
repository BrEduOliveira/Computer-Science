public class ExceptionA {
	try {
		throw new Exception();
	} catch (ExceptionB eb) {
		System.out.println(eb);
	}

	try {
		throw new Exception();
	} catch (ExceptionC ec) {
		System.out.println(ec);
	}
}