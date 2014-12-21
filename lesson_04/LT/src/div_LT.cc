#include "div_LT.hh"

div_LT::div_LT(sc_module_name name_)
  : sc_module(name_)
  , target_socket("target_socket")
  , pending_transaction(NULL)
{

  target_socket(*this);

}

void div_LT::b_transport(tlm::tlm_generic_payload& trans, sc_time& t)
{

  timing_annotation = SC_ZERO_TIME;

  ioDataStruct = *((iostruct*) trans.get_data_ptr());

  if (trans.is_write()) {
    div_function();
    trans.set_response_status(tlm::TLM_OK_RESPONSE);
    *((iostruct*) trans.get_data_ptr()) = ioDataStruct;
  } 
  else if (trans.is_read()){
    ioDataStruct.result = tmp_result;
    *((iostruct*) trans.get_data_ptr()) = ioDataStruct;

  }

  t += timing_annotation;
}

bool div_LT::get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data)
{
  return false;
}

tlm::tlm_sync_enum div_LT::nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_time& t)
{
  return tlm::TLM_COMPLETED;
}

unsigned int div_LT::transport_dbg(tlm::tlm_generic_payload& trans)
{
  return 0;
}


void div_LT:: div_function()
{
	double a, b;
	a = ioDataStruct.a;
	b = ioDataStruct.b;
	tmp_result = a*b;	

	//cout<<"\na =" << a;
	//cout<<"\nb =" << b;
	//cout<<"\nresult =" << tmp_result;

}



// Initialization:
void div_LT:: end_of_elaboration()
{

}

void div_LT:: reset()
{

}
