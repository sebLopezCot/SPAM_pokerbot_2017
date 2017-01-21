package pokerbots.spam_framework.action;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;

public class Action {
	
	public String actor;
	
	private static HashMap<String, Class<?>> stringToClass;
	
	private static void init(){
		stringToClass = new HashMap<String, Class<?>>();
		stringToClass.put("BET", Bet.class);
		stringToClass.put("CALL", Call.class);
		stringToClass.put("CHECK", Check.class);
		stringToClass.put("DEAL", Deal.class);
		stringToClass.put("DISCARD", Discard.class);
		stringToClass.put("FOLD", Fold.class);
		stringToClass.put("POST", Post.class);
		stringToClass.put("RAISE", Raise.class);
		stringToClass.put("REFUND", Refund.class);
		stringToClass.put("SHOW", Show.class);
		stringToClass.put("TIE", Tie.class);
		stringToClass.put("WIN", Win.class);
	}
	
	public static Action create(String input){
		if(stringToClass == null){
			init();
		}
		
		String[] data = input.split(":");

		String actionType = data[0];
		int numParams = data.length - 1;
		Object[] params = new Object[numParams];
		for(int i=0; i < numParams; i++) {
			params[i] = data[i+1];
		}
		
		if(stringToClass.containsKey(actionType)) {
			Class<?> c = stringToClass.get(actionType);
			try {
				Constructor<?> constructor = c.getConstructor();
				try {
					return (Action) constructor.newInstance(params);
				} catch (InstantiationException | IllegalAccessException
						| IllegalArgumentException | InvocationTargetException e) {
					e.printStackTrace();
				}
			} catch (NoSuchMethodException | SecurityException e) {
				e.printStackTrace();
			}
		}
		
		return null;
	}
}
