include "assembly.h"
include "machine.h"

public class ordonanceur {
	hashMap listComponentStartedAndReferences <instance, refInstance>;

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
	/* 					CONNEXION DIRECTE ENTRE LES COMPOSANTS 					*/
	/* ------------------------------------------------------------------------ */
	externalConnexion (Declare d){
		for (each cP in d.getconfigPort()){
			listComponentStartedAndReferences(
				cP.getInstanceIn()).connect(cP.getPortIn().getName(),
				listComponentStartedAndReferences(cP.getPortOut()),
				cP.getPortOut().getName()
			);
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
	    if (!comp.isRunning()){
	    	comp.setVoid();
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
		    	for (each inst in (sequence)i.getDeclare().getAllInstruction()){
		    		startInstance(instr);
		    	}
			    ajoutDeclare((sequence)i.getDeclare());
			    externalConnexion((sequence)i.getDeclare());

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
			    supDeclare();
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
			startInstance(instr);
		}

		externalConnexion(ActualDeclare);


		execInstruction(monAssemblage.getInstruction());
	}



}

