
	// Return the result
	/**
    // Check which polynomial has the higer degree
    if ((this -> find_degree_of()) >= other.find_degree_of()) {

        // Iterate through all the terms in both of the polynomials
        for (int curr_power = this -> find_degree_of(); curr_power >= 0; curr_power--) {

            // Check if the polynomials contain the power
            // If power is there, then add up the coefficients.
            // Otherwise, keep one of the polynomials' coefficient
            if ((this -> poly).find(curr_power) != (this -> poly).end()) {

                if (other.poly.find(curr_power) != other.poly.end()) {
                    result.poly[curr_power] = (this -> poly)[curr_power] + other.poly[curr_power];
                } else {
                    result.poly[curr_power] = (this -> poly)[curr_power];
                }
                
            } else {
                
                // If both of the polynomials' coefficients are 0, then don't 
                // insert any term to keep the non-zero policy consistent
                if (other.poly.find(curr_power) != other.poly.end()) {
                    result.poly[curr_power] = other.poly[curr_power];
                }
            }

        }

    } else {
        
        // Iterate through all the terms in both of the polynomials
        for (int curr_power = other.find_degree_of(); curr_power >= 0; curr_power--) {

            // Check if the polynomials contain the power
            // If power is there, then add up the coefficients.
            // Otherwise, keep one of the polynomials' coefficient
            if (other.poly.find(curr_power) != other.poly.end()) {

                if ((this -> poly).find(curr_power) != (this -> poly).end()) {
                    result.poly[curr_power] = (this -> poly)[curr_power] + other.poly[curr_power];
                } else {
                    result.poly[curr_power] = other.poly[curr_power];
                }
                
            } else {
                
                // If both of the polynomials' coefficients are 0, then don't 
                // insert any term to keep the non-zero policy consistent
                if ((this -> poly).find(curr_power) != (this -> poly).end()) {
                    result.poly[curr_power] = (this -> poly)[curr_power];
                }
            }

        }

    }**/


/* WIP- THREADING FOR MULTIPLICATION
void multiply_term(power curr_power, coeff curr_coeff, const polynomial other, polynomial &temp, int k) {
  auto other_begin = other.get_poly().begin();
  auto other_end = other.get_poly().end();
  cout << "this curr: " << curr_coeff << "x^" << curr_power << endl;
  while (other_begin != other_end) {
    temp.insert_poly(curr_power + (*other_begin).first, curr_coeff * (*other_begin).second);
    cout << "other curr: " << (*other_begin).second << "x^" << (*other_begin).first << endl;
    cout << "temp:";
    temp.print();
    other_begin++;
  }
  cout << endl;
}

// Multiplies two polynomials (polynomial * polynomial) and returns the result
polynomial polynomial::operator*(const polynomial& other) const {
  polynomial zero;
  int size = this->poly.size();
  vector<polynomial> temps(size);

  // initialize temps vector
  for (int i = 0; i < size; i++) {
    temps.at(i) = zero;
  }

  int k = 1;

  // initialize threads vector AND call threads
  vector<thread> threads;
  int i = 0;
  for (auto iter = (this -> poly).begin(); iter != (this -> poly).end(); iter++) {
    polynomial other_copy = other;
    threads.push_back(thread(multiply_term, iter->first, iter->second, other_copy, ref(temps.at(i)), k));
    threads.at(i);
    i++;
  }

  // wait for threads to finish
  for (int i = 0; i < size; i++) {
    threads.at(i).join();
  }

  // sum temps for result
  polynomial result;
  for (polynomial p : temps) {
    result = result + p;
  }

  return result;
}
*/
