include "assembly.h"
include "machine.h"

public class ordonanceur {
	hashMap refInternalPort <(instance, port), refPort>;
	hashMap listComponentStartedAndReferences <instance, refInstance>
	hashMap listDataSend <(instance, port), boolean>;

	Declare ActualDeclare;

	pile ([Declare]) pileActualDeclare;

	/* ------------------------------------------------------------------------ */
	/* 					FONCTION DETERMINISTE POUR LA MACHINE 					*/
	/* ------------------------------------------------------------------------ */
	getMachineWithDisponibleRessource(){
		//TODO 
		//C'est ce qui permet de regarder l'ensemble des machines et de renvoyer une machine qui dispose des ressources demandé (ram, cpu ...)
	}
	/* ------------------------------------------------------------------------ */
	/* 					FONCTION D'INSTANCIATION DE COMPOSANT 					*/
	/* ------------------------------------------------------------------------ */
	refInstance startInstance(Instance i){
	    if (empty(listComponentStartedAndReferences.get(i))){
	      Ressources r = i.getNecessaryRessource(); //optionnal
	      Machine m = this.getMachineWithDisponibleRessource(r);
	      refInstance componentStart = m.startComponent(i.getStartingParameters);
	      listComponentStartedAndReferences.add(i, componentStart);
	      connectAllOutPort(componentStart, i);
	      return componentStart;
	    }else{
	      return listComponentStartedAndReferences.get(i);
	    }
	}
	/* ------------------------------------------------------------------------ */
	/* 					FONCTION DE CONNEXION DES PORT DE SORTIE 				*/
	/* ------------------------------------------------------------------------ */
	connectAllOutPort(refInstance rI, Instance i){
	    for (each port in i.getAllOutPort()){
	        rI.connect(port.getName, refInternalPort (i, port);
	    }
	}
	/* ------------------------------------------------------------------------ */
	/* 					CONNEXION ENTRE DEUX PORT DE COMPOSANT 					*/
	/* ------------------------------------------------------------------------ */
	connexion (refInstance ref1, refInstance ref2, String portName1, String portName2){
		

	}
	/* ------------------------------------------------------------------------ */
	/* 				FONCTION D'ENVOIE DE DONNÉE VERS LE COMPOSANT 				*/
	/* ------------------------------------------------------------------------ */
	sendDataToInstance(Data d, refInstance componentStart, Port p){
	    if (!empty(listDataSend.get(componentStart, p))){
	      componentStart.sendDataForPort(data, port.getname());
	      listDataSend.add(componentStart, p, true);
	    }
	}
	/* ------------------------------------------------------------------------ */
	/* 					FONCTION DE DEMARRAGE D'UN COMPOSANT 					*/
	/* ------------------------------------------------------------------------ */
	lancement(instance i){
	    RefComponnent comp = listComponentStartedAndReferences.get(i);
	    if (comp == null){
	        comp = startInstance(i);
	    }
	    for (each Port p in i){
	        for (each ConfigPort cp in ActualDeclare.getconfigPort()){
	            if (cp.in == p){
	            	data = refInternalPort(cp.out.getInstance(), cp.out.getPort()).getValue();
	                if (data != null) {
	                    sendDataToInstance(data, comp, p);
	                }else{
	                    comp.setvoid(p.getname());
	                }
	            }
	        }
	    }
	}
	/* ------------------------------------------------------------------------ */
	/* 						AJOUT D'UN DECLARE EXTERNE							*/
	/* ------------------------------------------------------------------------ */
	ajoutDeclare(Declare d){
		pileActualDeclare.push(d);
		Declare act = new Declare ();
		for (each d in pileActualDeclare){
			act.add(d);
		}
		actualDeclare = act;

	}
	/* ------------------------------------------------------------------------ */
	/* 			ATTENTE DE RECEPTION DE TOUTE LES DONNÉES SORTANTES				*/
	/* ------------------------------------------------------------------------ */
	attenteReceptionTotale(Instruction i){
		boolean receptionTotale = false;
		boolean internalReception = false;
		while (!receptionTotale){
			sleep(10);
			internalReception = true;
			for (each pOut in i.getAllOutPort()){
				if (refInternalPort(pOut, i) == null){
					internalReception = false;
				}
			}
			if (internalReception){
				receptionTotale = true;
			}
		}
	}
	/* ------------------------------------------------------------------------ */
	/* 					SUPRRESSION D'UN DECLARE EXTERNE						*/
	/* ------------------------------------------------------------------------ */
	supDeclare(){
		pileActualDeclare.pull();
		Declare act = new Declare ();
		for (each d in pileActualDeclare){
			act.add(d);
		}
		actualDeclare = act;

	}
	/* ------------------------------------------------------------------------ */
	/* 						TRAITEMENT D'INSTRUCTION 							*/
	/* ------------------------------------------------------------------------ */
	execInstruction (Instruction i){
	    switch (i.getType()){
		    case createInstance :
		     	startInstance((createInstance)i.getInstance());
		    	break;

		    case execTask : 
		    	lancement((execTask)i.getInstance());
		    	attenteReceptionTotale((execTask)i.getInstance());
		    	break;

		    case sequence : 
			    ajoutDeclare((sequence)i.getDeclare());

			    for (each instr in (sequence)i.declare.getAllInstruction()){
			        for (each pO in instr.getAllPortOut()){
			            refInternalPort(pO, instr) = new refPort ();
			        }
			        
			    }
			    for (each instr in (sequence)i.getAllInstruction()){
			        execInstruction (instr);
			    }
			    for (each instr in (sequence)i.declare.getAllInstruction()){
			        for (each pO in instr.getAllPortOut()){
			            refInternalPort(pO, instr).delete();
			        }
			        
			    }
			    supDeclare
		    	break;    
	    }
	}
	/* ------------------------------------------------------------------------ */
	/* 									MAIN 									*/
	/* ------------------------------------------------------------------------ */
	main (){
		assemblage monAssemblage = cin << path; //On determine l'assemblage qu'on veux utiliser
		pileActualDeclare.push(monAssemblage.getDeclare());
		ActualDeclare = monAssemblage.getDeclare();

		for (each instr in monAssemblage.getDeclare().getAllInstruction()){
			for (each pOut in instr.getAllPortOut()){
				refInternalPort(pOut, instr) = new refPort();
			}
		}

		

		execInstruction(monAssemblage.getInstruction());
	}



}

