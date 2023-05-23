#ifndef CHOCOLATE_HPP
#define CHOCOLATE_HPP

template <class T>
class Chocolate {
protected:
	T id;

	Chocolate(const T& id);

	bool isIdValid() const;
};

template<class T>
bool Chocolate<T>::isIdValid() const {
	return true;
}

template<class T>
Chocolate<T>::Chocolate(const T& id) : id(id) {
	
}

#endif // !CHOCOLATE_HPP
