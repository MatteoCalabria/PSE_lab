#ifndef __div_AT4_HPP__
#define __div_AT4_HPP__

#include <systemc.h>
#include <tlm.h>
#include "define_AT4.hh"

class div_AT4
  : public sc_module
  , public virtual tlm::tlm_fw_transport_if<>
{

 public:

  tlm::tlm_target_socket<> target_socket;

  virtual void b_transport(tlm::tlm_generic_payload& trans, sc_time& t);

  virtual bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data);

  virtual tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_time& t);

  virtual unsigned int transport_dbg(tlm::tlm_generic_payload& trans);

  iostruct  ioDataStruct;
  tlm::tlm_generic_payload* pending_transaction;

  sc_event io_event;
  void IOPROCESS();

  double tmp_result;

  void div_function();


  void end_of_elaboration();

  void reset();
  
  SC_HAS_PROCESS(div_AT4);

  div_AT4(sc_module_name name_);
  
};

#endif

