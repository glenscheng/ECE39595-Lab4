
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


/* 231115 WIP- THREADING FOR MULTIPLICATION
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

/* 231116 WIP- THREADING FOR MULTIPLICATION: works, gotta find out if it is faster or not, also account for only 128 threads
static void multiply_terms(power this_power, coeff this_coeff, power other_power, coeff other_coeff, polynomial &temp) {
  temp.insert_poly(this_power + other_power, this_coeff * other_coeff);
}

// Multiplies two polynomials (polynomial * polynomial) and returns the result
polynomial polynomial::operator*(const polynomial& other) const {
  polynomial zero;
  int size = (*this).poly.size() * other.poly.size();
  vector<polynomial> temps(size, zero); // initialize temps vector to all 0 polynomials

  // int k = 1;
  
  // initialize threads vector AND call threads
  vector<thread> threads;
  int i = 0;
  auto this_end = (*this).poly.rend();
  auto other_end = other.poly.rend();
  for (auto this_iter = (*this).poly.rbegin(); this_iter != this_end; this_iter++) {
    for (auto other_iter = other.poly.rbegin(); other_iter != other_end; other_iter++) {
      power this_power = (*this_iter).first;
      coeff this_coeff = (*this_iter).second;
      power other_power = (*other_iter).first;
      coeff other_coeff = (*other_iter).second;
      // cout << "(before calling threads) this: " << this_coeff << "x^" << this_power << ", other: " << other_coeff << "x^" << other_power << endl;
      threads.push_back(thread(multiply_terms, this_power, this_coeff, other_power, other_coeff, ref(temps.at(i))));
      //threads.push_back(thread(multiply_terms, this_power, this_coeff, other_power, other_coeff, ref(result)));
      threads.at(i);
      i++;
    }
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





/* 231120- old parallel implementation
  // PARALLEL (threads = 4)
  polynomial zero;
  int size = 4; // using only 4 threads
  int this_terms_per_thread = (*this).poly.size() / size;
  vector<polynomial> temps(size, zero); // initialize temps vector to all 0 polynomials

  // create vectors for powers and coeffs for `other`
  map<power, coeff> other_vals1;
  map<power, coeff> other_vals2;
  map<power, coeff> other_vals3;
  map<power, coeff> other_vals4;
  auto other_end = other.poly.rend();
  for (auto other_iter = other.poly.rbegin(); other_iter != other_end; other_iter++) {
    power other_power = (*other_iter).first;
    coeff other_coeff = (*other_iter).second;
    other_vals1.insert({other_power, other_coeff});
    other_vals2.insert({other_power, other_coeff});
    other_vals3.insert({other_power, other_coeff});
    other_vals4.insert({other_power, other_coeff});
  }

  // create vectors for powers and coeffs for `this` / 4
  auto this_iter = (*this).poly.rbegin();
  auto this_end = (*this).poly.rend();
  // for 1st thread:
  map<power, coeff> this_vals1;
  int i = 0;
  while (i < this_terms_per_thread) {
    this_vals1.insert({(*this_iter).first, (*this_iter).second});
    i++;
    this_iter++;
  }
  // for 2nd thread:
  map<power, coeff> this_vals2;
  i = 0;
  while (i < this_terms_per_thread) {
    this_vals2.insert({(*this_iter).first, (*this_iter).second});
    i++;
    this_iter++;
  }
  // for 3rd thread:
  map<power, coeff> this_vals3;
  i = 0;
  while (i < this_terms_per_thread) {
    this_vals3.insert({(*this_iter).first, (*this_iter).second});
    i++;
    this_iter++;
  }
  // for 4th thread:
  map<power, coeff> this_vals4;
  while (this_iter != this_end) {
    this_vals4.insert({(*this_iter).first, (*this_iter).second});
    this_iter++;
  }

  // initialize threads vector AND call threads
  vector<thread> threads;
  i = 0;
  threads.push_back(thread(multiply_terms_4, this_vals1, other_vals1, ref(temps.at(i))));
  threads.at(i);
  i++;
  threads.push_back(thread(multiply_terms_4, this_vals2, other_vals2, ref(temps.at(i))));
  threads.at(i);
  i++;
  threads.push_back(thread(multiply_terms_4, this_vals3, other_vals3, ref(temps.at(i))));
  threads.at(i);
  i++;
  threads.push_back(thread(multiply_terms_4, this_vals4, other_vals4, ref(temps.at(i))));
  threads.at(i);


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
*/
  
/* 231120- even older? parallel implementation
  // PARALLEL (threads = num terms)
  polynomial zero;
  int size = (*this).poly.size() * other.poly.size();
  vector<polynomial> temps(size, zero); // initialize temps vector to all 0 polynomials

  // initialize threads vector AND call threads
  vector<thread> threads;
  int i = 0;
  auto this_end = (*this).poly.rend();
  auto other_end = other.poly.rend();
  for (auto this_iter = (*this).poly.rbegin(); this_iter != this_end; this_iter++) {
    for (auto other_iter = other.poly.rbegin(); other_iter != other_end; other_iter++) {
      power this_power = (*this_iter).first;
      coeff this_coeff = (*this_iter).second;
      power other_power = (*other_iter).first;
      coeff other_coeff = (*other_iter).second;
      // cout << "(before calling threads) this: " << this_coeff << "x^" << this_power << ", other: " << other_coeff << "x^" << other_power << endl;
      threads.push_back(thread(multiply_terms, this_power, this_coeff, other_power, other_coeff, ref(temps.at(i))));
      //threads.push_back(thread(multiply_terms, this_power, this_coeff, other_power, other_coeff, ref(result)));
      threads.at(i);
      i++;
    }
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
*/

/* 231120- old sequential implementation i think
  polynomial result;

  // Iterate through all the terms in the first polynomial 
  for (auto iter = (this -> poly).begin(); iter != (this -> poly).end(); iter++) {

    // Temporary polynomial for individual sums 
    polynomial temp;

    // Iterate through all the terms in the second polynomial
    for (auto other_iter = other.poly.begin(); other_iter != other.poly.end(); other_iter++) {
      temp.poly[(iter -> first) + (other_iter -> first)] = (iter -> second) * (other_iter -> second);
    }

    result = result + temp;
  }

  return result;
*/



// 231120- old function for threading for polynomial * polynomial
//static void multiply_terms(power this_power, coeff this_coeff, power other_power, coeff other_coeff, polynomial &temp) {
//  temp.insert_poly(this_power + other_power, this_coeff * other_coeff);
//}
