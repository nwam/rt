// This file contains the definition the ViewPlane class

#include "ViewPlane.h"

#include <stdlib.h>
#include "Regular.h"
#include "MultiJittered.h"
// ---------------------------------------------------------------- default constructor	
						
ViewPlane::ViewPlane(void)							
	: 	hres(400), 
		vres(400),
		s(1.0),
		num_samples(1),
		gamma(1.0),
		inv_gamma(1.0),
		show_out_of_gamut(false),
		sampler_ptr(NULL)
{}


// ---------------------------------------------------------------- copy constructor

ViewPlane::ViewPlane(const ViewPlane& vp)   
	:  	hres(vp.hres),  
		vres(vp.vres), 
		s(vp.s),
		num_samples(vp.num_samples),
		gamma(vp.gamma),
		inv_gamma(vp.inv_gamma),
		show_out_of_gamut(vp.show_out_of_gamut),
		sampler_ptr(NULL)
{}


// ---------------------------------------------------------------- assignment operator

ViewPlane& 
ViewPlane::operator= (const ViewPlane& rhs) {
	if (this == &rhs)
		return (*this);
		
	hres 				= rhs.hres;
	vres 				= rhs.vres;
	s					= rhs.s;
	num_samples			= rhs.num_samples;
	gamma				= rhs.gamma;
	inv_gamma			= rhs.inv_gamma;
	show_out_of_gamut	= rhs.show_out_of_gamut;
	
	return (*this);
}


// -------------------------------------------------------------- destructor

ViewPlane::~ViewPlane(void) {}


// ------------------------------------------------------------------------------ set_samples

void
ViewPlane::set_samples(const int n) {
	num_samples = n;

	if(sampler_ptr) {
	    delete sampler_ptr;
	    sampler_ptr = NULL;
	}

	if(num_samples > 1)
	    sampler_ptr = new MultiJittered(num_samples);
	else
	    sampler_ptr = new Regular(1);
}


// -------------------------------------------------------------- set_sampler

void
ViewPlane::set_sampler(Sampler* sp) {
	if(sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
	
	num_samples = sp->get_num_samples();
	sampler_ptr = sp;
}
