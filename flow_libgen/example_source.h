// Dox v1.6.0 example project
// // the purpose of this example is to demonstrate the capabilities of Sunsys Dox, nothing more, nothing less...



/**
 *  This is a macro.
 */
#define appArrayElementCount(array) (size_t(sizeof(array)/sizeof((array)[0])))



/**
 *  This is a typedef.
 */
typedef unsigned int    uint;
/**
 *  This is another typedef.
 */
typedef unsigned long   ulong;



/**
 *  This is a namespace.
 *
 *  @since  v1.0
 *  @author Narech Koumar
 */
namespace ANamespace
{

	/**
	 *  @brief  This is an inner namespace.
	 *
	 *  This is an inner namespace within ANamespace.
	 *
	 *  @see ANamespace
	 */
	namespace InnerNamespace
	{
		/**
		 *  This is an enumeration.
		 */
		enum Enum
		{
			/**
			 *  This is EnumValue1.
			 */
			EnumValue1  = 0,
			/**
			 *  This is EnumValue2.
			 */
			EnumValue2  = 0x03ff,
			/**
			 *  This is EnumValue3.
			 */
			EnumValue3  = 0x0c00,
			/**
			 *  This is EnumValueX. Its value is set automatically by the compiler.
			 */
			EnumValueX
		};


		/**
		 *  One documentation block covers several functions. Neat!
		 *
		 *  Returns the smaller of two values.
		 *
		 *  @param  valueA  an argument
		 *  @param  valueB  another argument
		 *  @return the smaller of a and b
		 *  @{
		 */
		inline int      min(int valueA, int valueB)             throw() {   return valueA < valueB ? valueA : valueB;   }
		inline short    min(short valueA, short valueB)         throw() {   return valueA < valueB ? valueA : valueB;   }
		inline long     min(long valueA, long valueB)           throw() {   return valueA < valueB ? valueA : valueB;   }
		inline Struct   min(Struct valueA, Struct valueB)       throw() {   return valueA < valueB ? valueA : valueB;   }
		/** @} */

		/**
		 *  Returns the larger of two numbers. If the arguments have the same value,
		 *  the result is that same value.
		 *
		 *  @param  valueA  an argument
		 *  @param  valueB  another argument
		 *  @return the larger of @c valueA and @c valueB
		 */
		inline char     max(char valueA, char valueB)
		{
			return valueA > valueB ? valueA : valueB;
		}
	} // namespace InnerNamespace


	/**
	 *  This is a struct.
	 */
	struct Struct
	{
		/**
		 *  This is a function foo. Here is some @e emphasised text. Here is some @b bold text.
		 *
		 *  And here is some @c typewriter text, note that it is in a new paragraph. You can also specify
		 *  different text styles like this: <i>emphasised text</i>, <b>bold text</b>, <tt>some typewriter
		 *  (code) text</tt>, <sub>subscript text</sub> and <sup>superscript text</sup>, also here is
		 *  <small>some small text</small>.
		 *
		 *  We can also do lists:
		 *  <ul>
		 *      <li>item 1
		 *      <li>item 2
		 *      <li>item 3
		 *  </ul>
		 *  <ol>
		 *      <li>numbered item 1
		 *      <li>numbered item 2
		 *      <li>numbered item 3
		 *  </ol>
		 *
		 *  And tables:
		 *  <table>
		 *      <tr>
		 *          <th>Item</th>
		 *          <th>Description</th>
		 *      </tr>
		 *      <tr>
		 *          <td><tt>xx</tt></td>
		 *          <td>bla</td>
		 *      </tr>
		 *      <tr>
		 *          <td><tt>yy</tt></td>
		 *          <td>bla-bla</td>
		 *      </tr>
		 *  </table>
		 *
		 *  Here is some preformatted text:
		 *
		 *  <pre>
		 *      This
		 *          is
		 *              preformatted   text!
		 *  </pre>
		 *
		 *  @param  a   an argument
		 *  @param  b   another argument
		 *  @param  c   third argument
		 *
		 *  @return some magical value
		 *
		 *  @pre    a == 0, b >= 0 and c > 0
		 *
		 *  @post   none at all
		 *
		 *  @remarks    this is truly a remarkable function
		 *
		 *  @see    bar(), func()
		 */
		int foo(int a, uint b, ulong c) throw()
		{
			return 0;
		}
		/**
		 *  Bar is a function. Unfortionally it has become obsolete.
		 *
		 *  @return I have no idea.
		 *
		 *  @throw  Struct      due to excessive use of hakuna matata
		 *  @throw  abrakadabra whenever it feels like throwing up
		 *
		 *  @deprecated Because it is a very ancient function, no longer in use.
		 */
		uint bar()
		{
			return 0;
		}

		protected:
		/**
		 *  A protected variable. Hands off!
		 */
		const bool var;

	};
} // namespace ANamespace



/**
 *  Just another namespace... Move along!
 */
namespace AnotherNamespace
{
}



/**
 *  Hi! My name is globalVar1. I am very long, static and quite volatile.
 */
static volatile long globalVar1;
/**
 *  Hello, my name is globalVar2 and I am very ulong. Both globalVar1 and I are live at a global scope.
 *  Well, isn't that nice.
 */
const ulong globalVar2 = 12345;



/**
 *  A template function at a global scope.
 *
 *  @param  in  an argument of type T
 */
	template <typename T>
inline void func(T in)
{
}



/**
 *  This is a non-copyable type concept. Copy constructor and assignment operator
 *  are disabled (declared private).
 */
struct NonCopyableType
{
	protected:
		/**
		 *  Default constructor.
		 */
		NonCopyableType()   {}
		/**
		 *  The destructor.
		 */
		~NonCopyableType()  {}

	private:
		/**
		 *  Copy constructor. Isn't displayed unless "formatPrivate" option is set to True.
		 */
		NonCopyableType(const NonCopyableType&);
		/**
		 *  Assignment Operator. Isn't displayed unless "formatPrivate" option is set to True.
		 */
		const NonCopyableType& operator=(const NonCopyableType&);
};



/**
 *  This is a base class for the DerivedClass type. It is a demonstration of
 *  inheritance graphs.
 *
 *  @see    DerivedClass
 */
template <typename Base, typename Container>
class BaseClass
{
	protected:
		Base base;

		/**
		 *  Default constructor.
		 */
		BaseClass()
		{}
		/**
		 *  Another constructor.
		 *
		 *  @param  inBase  some argument
		 */
		explicit BaseClass(const Base& inBase):
			base(inBase)
	{}

	public:
		/**
		 *  Some member methods.
		 *
		 *  @{
		 */
		Int     size()                                      const;
		UInt    hashCode()                                  const;
		Bool    equals(const BaseClass& object)             const;
		Int     compareTo(const BaseClass& object)          const;
		Void    exchangeWith(BaseClass& object)             ;
		String  toString()                                  const;
		/** @} */

		/**
		 *  Let's make this class abstract.
		 *
		 *  @return a value
		 */
		virtual int abstractMethod() = 0                    throw();
};


/**
 *  This is the derived class. It is here to demonstrate
 *  inheritance graphs. Note the use of templates.
 *
 *  Multiple inheritance is supported and is drawn correctly as well.
 *
 *  @see    NonCopyableType, BaseClass
 */
template <typename Base, typename Container, typename ElementType>
class DerivedClass:
	private NonCopyableType, public BaseClass<Base, Container>
{
	public:
		/**
		 *  This is an inner struct.
		 */
		struct InnerStruct
		{
			/**
			 *  Long names are informative; extremely long names are annoying!
			 */
			int     howComeThisDocumentationToolRefersToFunctionsAsMethods;
			float   whyDoesThisDocumentationToolReferToVariablesAsFields;
			double  trouble;
		};
		/**
		 *  A bunch of member methods.
		 *
		 *  @{
		 */
		Bool    contains(const ElementType& object)         const;
		Bool    containsAll(const Container& container)     const;
		template <typename ContainerX>
			Bool    containsAll(const ContainerX& container)    const;
		Bool    remove(const ElementType& object)           ;
		Int     removeAll(const Container& container)       ;
		template <typename ContainerX>
			Int     removeAll(const ContainerX& container)      ;
		Int     retainAll(const Container& container)       ;
		template <typename ContainerX>
			Int     retainAll(const ContainerX& container)      ;
		/** @} */

		/**
		 *  Implement abstractMethod, so that we aren't abstract anymore.
		 *
		 *  @return a value
		 */
		int abstractMethod()                                throw()
		{
			return 0;
		}
};


/* EOF */

