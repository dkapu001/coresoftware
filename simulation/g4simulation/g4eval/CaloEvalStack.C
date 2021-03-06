
#include "CaloEvalStack.h"

#include "CaloRawClusterEval.h"
#include "CaloTruthEval.h"

#include <phool/getClass.h>
#include <phool/PHCompositeNode.h>

#include <string>

using namespace std;

CaloEvalStack::CaloEvalStack(PHCompositeNode* topNode, std::string caloname)
  : _clustereval(topNode,caloname) {
}

void CaloEvalStack::next_event(PHCompositeNode* topNode) {
  _clustereval.next_event(topNode);
}

