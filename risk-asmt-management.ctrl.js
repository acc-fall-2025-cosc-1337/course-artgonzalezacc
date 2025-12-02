"use strict";
scorApp.controller('riskAssessmentManagementController', function($scope, $location, $anchorScroll, $confirm, $mdDialog, $mdMedia, $rootScope, riskAssessmentManagementFactory, dialogMessageFactory, formUtilFactory, UserAuth, $state, riskAsmtEntryFactory, localSessionFactory) {
    $rootScope.setChildTab('administration_contract_management_risk_assessment_entry');
    $rootScope.displayContractManagementSubmenu = true;
    $scope.riskAssessmentObj = {};
    $scope.oldRiskAssessmentObj = {};
    $scope.isAddNewRiskAssessment = true;
    $scope.riskAssessments = [];
    $scope.rowCount = 0;
    $scope.otherRiskFactorInfo = {};
    $scope.displayDeleteButton = false;
    $scope.riskAsmtIndex = 0;
    $scope.selectedAll = false;
    $scope.selectOrDeselectLabel = 'Select All';
    $scope.displayOnlyRiskAssessment = false;
    $scope.displayRecordSavedMsg = false;
    $scope.displayDeleteOtherRiskFactorsButton = false;
    $scope.vm = { currentPage: 1 };
    $scope.noOfRecordsPerPage = "5";
    $scope.noOfRec = $scope.noOfRecordsPerPage;
    $scope.reverseSort = false;
    $scope.errorFromRestService = false;
    $scope.displayRecordSavedMsg = false;
    $scope.showNoRecordsMessage = false;
    $scope.unableToRetrieveTemplate = false;
    $scope.otherRiskLevelLookupList = [];
    $scope.primaryRiskAssessorLookupList = [];
    $scope.displayLastUpdatedBySection = true;
    $scope.invalidRiskAssessmentDate = false;
    $scope.invalidRiskAssessmentFiscalYear = false;
    $scope.riskAssessmentDateGreaterThanToday = false;    
    $scope.displayRecordDeletedMsg = false;
    $scope.displayPagination = false;
    $scope.isOtherRiskLevelRequired = false;
    $scope.unableToRetrieveContractHeader = false;
    $scope.disableContractHeaderAndRiskAssessmentSection = true;
    $scope.required = false;
    var msg;
	
    $scope.isAddEditRiskAsmtVisible = false;
	
	$scope.riskRangeTypeTotalScore = [];
	$scope.riskRangeTypeRiskLevel = [];
	$scope.baseLineRiskLevelScore = 0;
	$scope.contractBaseLineRiskLevel = "";
	$scope.baseLineRiskRangeTypeRanges = [];
	$scope.isAddEditRiskAsmtVisibleB = false;
	$scope.addEditRiskAmtLabel = "";
    $scope.isAddRiskAssessment = false;
	$scope.isEditRiskAssessment = false;
	$scope.contractBaseEvaluation = {};
	$scope.contractClosed = true;

    $scope.loadUserAgency = function() {
        UserAuth.uAgency();
    }
    $scope.loadUserAgency();

    $scope.resetFormAndSearchNewContractNumber = function() {
		$scope.getContractBaseEvaluation();

        riskAssessmentManagementFactory.getContractHeader($scope.contractNumber).then(function(response) {
            if (response.success) {
                $scope.unableToRetrieveContractHeader = false;
                $scope.data = response.data;
                $scope.contractInfo = $scope.data;
                $scope.getContractRiskAssessmentsB($scope.contractInfo.contractId, $scope.vm.currentPage, $scope.noOfRecordsPerPage);
                $scope.disableContractHeaderAndRiskAssessmentSection = false;
                if ($scope.contractInfo.contractStatus.contractStatusId === "3" || $scope.contractInfo.contractStatus.contractStatusId === "4" || $scope.contractInfo.contractStatus.contractStatusId === "5" || $scope.contractInfo.contractStatus.contractStatusId === "13"
                     || $scope.contractInfo.contractStatus.contractStatusId === "14") {
                    $scope.disableAdd = true;
					$scope.contractClosed = true;
                } else {
                    $scope.disableAdd = false;
					$scope.contractClosed = false;
                }
            } else {
                $scope.contractInfo = {};
                $scope.unableToRetrieveContractHeader = true;
                $scope.errorMsg = response.error.error.description;
                $scope.disableContractHeaderAndRiskAssessmentSection = true;
                $scope.showNoRecordsMessage = true;
            }
        });
        $scope.isAddEditRiskAsmtVisible = false;
        $scope.displayOnlyRiskAssessment = false;
        $scope.displayRecordSavedMsg = false;
        $scope.displayRecordDeletedMsg = false;
        $scope.noOfRecordsPerPage = "5";
        $scope.contractRiskAsmtForm.$setPristine();
    };

    $scope.getContractHeader = function() {
        if ($scope.contractRiskAsmtForm.$dirty && !$scope.formNotChanged()) {
            msg = 'There are unsaved changes in the form. Do you want to discard?';
            dialogMessageFactory.getConfirmation(msg).then(function() {
                $scope.resetFormAndSearchNewContractNumber();
            }, function() {});
        } else {
            $scope.resetFormAndSearchNewContractNumber();
        }
    };

    $scope.getContractRiskAssessments = function(contractId, pageNumber, noOfRecordsPerPage) {
        riskAssessmentManagementFactory.getContractRiskAssessments(contractId, pageNumber - 1, noOfRecordsPerPage).then(function(response) {
            if (response.success) {
                $scope.data = response.data;
                $scope.riskAssessments = $scope.data._embedded.riskAssessmentSummaryList;
                $scope.totalItems = $scope.data.page.totalElements;
                $scope.showNoRecordsMessage = false;
                $scope.displayPagination = true;
            } else {
                $scope.riskAssessments = [];
                $scope.totalItems = 0;
                $scope.showNoRecordsMessage = false;
                $scope.displayPagination = false;
                if ($scope.displayRecordDeletedMsg && $scope.vm.currentPage - 1 > 0) {
                    $scope.vm.currentPage = $scope.vm.currentPage - 1;
                    $scope.getContractRiskAssessments($scope.contractInfo.contractId, $scope.vm.currentPage, $scope.noOfRecordsPerPage);
                }
            }
        });
    };

    $scope.getLookupValues = function() {
        riskAssessmentManagementFactory.getLookUpValues().then(function(response) {
            if (response.success) {
                $scope.data = response.data;
                $scope.otherRiskLevelLookupList = $scope.data.otherRiskLevelLookupList;
                $scope.primaryRiskAssessorLookupList = $scope.data.primaryRiskAssessorLookupList;
            }
        });
    };

    $scope.getLookupValues();

    $scope.InitializeNewRiskAssessment = function(scrollLocation) {
        $scope.contractRiskAsmtForm.$setPristine();
        $scope.riskAssessmentDateGreaterThanToday = false;
        riskAssessmentManagementFactory.getCurrentRiskAssessmentTemplate().then(function(response) {
            if (response.success) {
                $scope.data = response.data;
                $scope.riskAssessmentTemplate = $scope.data;
                $location.hash(scrollLocation);
                $anchorScroll();
                $scope.resetFormErrorMessages();
                $scope.displayLastUpdatedBySection = false;
                $scope.addEditRiskAmtLabel = "New Risk Assessment";
                $scope.isAddEditRiskAsmtVisible = true;
                $scope.isAddNewRiskAssessment = true;
                $scope.riskAssessmentObj = {
                    riskAssessmentDate: "",
                    riskAssessmentFiscalYear: "",
                    legalRiskPoint1: 0,
                    legalRiskPoint2: 0,
                    legalRiskPoint3: 0,
                    legalRiskPoint4: 0,
                    legalRiskPoint5: 0,
                    contractRiskPoint1: 0,
                    contractRiskPoint2: 0,
                    contractRiskPoint3: 0,
                    contractRiskPoint4: 0,
                    contractRiskPoint5: 0,
                    otherRiskFactorList: [],
                    riskAssessmentTemplateId: $scope.riskAssessmentTemplate.riskAssessmentTemplateId
                };
                $scope.displayOnlyRiskAssessment = false;
                $scope.calculateActiveLegalAndContractRiskFactors($scope.riskAssessmentTemplate);
            } else {
                $scope.unableToRetrieveTemplate = true;
            }
        });
        $scope.displayRecordSavedMsg = false;
        $scope.showNoRecordsMessage = false;
        $scope.displayRecordDeletedMsg = false;
        $scope.isOtherRiskLevelRequired = false;
        $scope.errorFromRestService = false;
        $scope.displayDeleteButton = false;
        $scope.displayDeleteOtherRiskFactorsButton = false;
        $scope.required = true;
        $scope.resetSelectAll();
    };

    $scope.showAddRiskAsmtPanel = function(scrollLocation) {
        if ($scope.contractRiskAsmtForm.$dirty && !$scope.formNotChanged()) {
            msg = 'There are unsaved changes in the form. Do you want to discard?';
            dialogMessageFactory.getConfirmation(msg).then(function() {
                $scope.InitializeNewRiskAssessment(scrollLocation);
            }, function() {});
        } else {
            $scope.InitializeNewRiskAssessment(scrollLocation);
        }
    };

    $scope.calculateBaselineRisk = function() {
        var baseRiskValue;
        if ($scope.riskAssessmentObj.contractRiskScore === undefined) {
            $scope.riskAssessmentObj.contractRiskScore = 0;
        }
        if ($scope.riskAssessmentObj.legalRiskScore === undefined) {
            $scope.riskAssessmentObj.legalRiskScore = 0;
        }

        $scope.riskAssessmentObj.baselineRiskScore = parseInt($scope.riskAssessmentObj.contractRiskScore) + parseInt($scope.riskAssessmentObj.legalRiskScore);
        baseRiskValue = $scope.riskAssessmentObj.baselineRiskScore;
        if (baseRiskValue <= $scope.riskAssessmentTemplate.baselineLowMax) {
            $scope.riskAssessmentObj.baselineRiskLevel = 'Low';
        } else if (baseRiskValue > $scope.riskAssessmentTemplate.baselineLowMax && baseRiskValue <= $scope.riskAssessmentTemplate.baselineMediumMax) {
            $scope.riskAssessmentObj.baselineRiskLevel = 'Medium';
        } else if (baseRiskValue > $scope.riskAssessmentTemplate.baselineMediumMax && baseRiskValue <= $scope.riskAssessmentTemplate.baselineHighMax) {
            $scope.riskAssessmentObj.baselineRiskLevel = 'High';
        }
    };

    $scope.calculateLegalRisk = function(index) {
        switch (index) {
            case 0:
                $scope.riskAssessmentObj.legalRiskPoint1 = angular.isUndefined($scope.riskAssessmentObj.legalRiskLevelScore1) ? 0 : $scope.riskAssessmentObj.legalRiskLevelScore1 * $scope.riskAssessmentTemplate.riskAssessmentTemplateLegals[index].weightMultiplier;
                break;
            case 1:
                $scope.riskAssessmentObj.legalRiskPoint2 = angular.isUndefined($scope.riskAssessmentObj.legalRiskLevelScore2) ? 0 : $scope.riskAssessmentObj.legalRiskLevelScore2 * $scope.riskAssessmentTemplate.riskAssessmentTemplateLegals[index].weightMultiplier;
                break;
            case 2:
                $scope.riskAssessmentObj.legalRiskPoint3 = angular.isUndefined($scope.riskAssessmentObj.legalRiskLevelScore3) ? 0 : $scope.riskAssessmentObj.legalRiskLevelScore3 * $scope.riskAssessmentTemplate.riskAssessmentTemplateLegals[index].weightMultiplier;
                break;
            case 3:
                $scope.riskAssessmentObj.legalRiskPoint4 = angular.isUndefined($scope.riskAssessmentObj.legalRiskLevelScore4) ? 0 : $scope.riskAssessmentObj.legalRiskLevelScore4 * $scope.riskAssessmentTemplate.riskAssessmentTemplateLegals[index].weightMultiplier;
                break;
            case 4:
                $scope.riskAssessmentObj.legalRiskPoint5 = angular.isUndefined($scope.riskAssessmentObj.legalRiskLevelScore5) ? 0 : $scope.riskAssessmentObj.legalRiskLevelScore5 * $scope.riskAssessmentTemplate.riskAssessmentTemplateLegals[index].weightMultiplier;
                break;
            default:
        }

        $scope.riskAssessmentObj.legalRiskScore = Number($scope.riskAssessmentObj.legalRiskPoint1) + Number($scope.riskAssessmentObj.legalRiskPoint2) + Number($scope.riskAssessmentObj.legalRiskPoint3) + Number($scope.riskAssessmentObj.legalRiskPoint4) + Number($scope.riskAssessmentObj.legalRiskPoint5);

        var totalScore = $scope.riskAssessmentObj.legalRiskScore;
        if (totalScore <= $scope.riskAssessmentTemplate.legalLowMax) {
            $scope.riskAssessmentObj.legalRiskLevel = 'Low';
        } else if (totalScore > $scope.riskAssessmentTemplate.legalLowMax && totalScore <= $scope.riskAssessmentTemplate.legalMediumMax) {
            $scope.riskAssessmentObj.legalRiskLevel = 'Medium';
        } else if (totalScore > $scope.riskAssessmentTemplate.legalMediumMax && totalScore <= $scope.riskAssessmentTemplate.legalHighMax) {
            $scope.riskAssessmentObj.legalRiskLevel = 'High';
        }
        $scope.calculateBaselineRisk();
    };

    $scope.calculateContractRisk = function(index) {
        var totalScore;
        switch (index) {
            case 0:
                $scope.riskAssessmentObj.contractRiskPoint1 = angular.isUndefined($scope.riskAssessmentObj.contractRiskLevelScore1) ? 0 : $scope.riskAssessmentObj.contractRiskLevelScore1 * $scope.riskAssessmentTemplate.riskAssessmentTemplateContracts[index].weightMultiplier;
                break;
            case 1:
                $scope.riskAssessmentObj.contractRiskPoint2 = angular.isUndefined($scope.riskAssessmentObj.contractRiskLevelScore2) ? 0 : $scope.riskAssessmentObj.contractRiskLevelScore2 * $scope.riskAssessmentTemplate.riskAssessmentTemplateContracts[index].weightMultiplier;
                break;
            case 2:
                $scope.riskAssessmentObj.contractRiskPoint3 = angular.isUndefined($scope.riskAssessmentObj.contractRiskLevelScore3) ? 0 : $scope.riskAssessmentObj.contractRiskLevelScore3 * $scope.riskAssessmentTemplate.riskAssessmentTemplateContracts[index].weightMultiplier;
                break;
            case 3:
                $scope.riskAssessmentObj.contractRiskPoint4 = angular.isUndefined($scope.riskAssessmentObj.contractRiskLevelScore4) ? 0 : $scope.riskAssessmentObj.contractRiskLevelScore4 * $scope.riskAssessmentTemplate.riskAssessmentTemplateContracts[index].weightMultiplier;
                break;
            case 4:
                $scope.riskAssessmentObj.contractRiskPoint5 = angular.isUndefined($scope.riskAssessmentObj.contractRiskLevelScore4) ? 0 : $scope.riskAssessmentObj.contractRiskLevelScore5 * $scope.riskAssessmentTemplate.riskAssessmentTemplateContracts[index].weightMultiplier;
                break;
            default:
        }

        $scope.riskAssessmentObj.contractRiskScore = Number($scope.riskAssessmentObj.contractRiskPoint1) + Number($scope.riskAssessmentObj.contractRiskPoint2) + Number($scope.riskAssessmentObj.contractRiskPoint3) + Number($scope.riskAssessmentObj.contractRiskPoint4) + Number($scope.riskAssessmentObj.contractRiskPoint5);

        totalScore = $scope.riskAssessmentObj.contractRiskScore;

        if (totalScore <= $scope.riskAssessmentTemplate.contractLowMax) {
            $scope.riskAssessmentObj.contractRiskLevel = 'Low';
        } else if (totalScore > $scope.riskAssessmentTemplate.contractLowMax && totalScore <= $scope.riskAssessmentTemplate.contractMediumMax) {
            $scope.riskAssessmentObj.contractRiskLevel = 'Medium';
        } else if (totalScore > $scope.riskAssessmentTemplate.contractMediumMax && totalScore <= $scope.riskAssessmentTemplate.contractHighMax) {
            $scope.riskAssessmentObj.contractRiskLevel = 'High';
        }

        $scope.calculateBaselineRisk();
    };

    $scope.InitializeExistingRiskAssessment = function(riskAssessment, scrollLocation) {
        $scope.required = false;
        $scope.invalidRiskAssessmentFiscalYear = false;
        $scope.riskAssessmentDateGreaterThanToday = false;
		$scope.isAddEditRiskAsmtVisibleB = false; 
        if (!angular.isUndefined($scope.contractRiskAsmtForm.riskAssessmentFiscalYear)) {
            $scope.contractRiskAsmtForm.riskAssessmentFiscalYear.$setValidity($scope.contractRiskAsmtForm.riskAssessmentFiscalYear.$errors, true);
        }
        $scope.invalidRiskAssessmentDate = false;
        if (!angular.isUndefined($scope.contractRiskAsmtForm.riskAssessmentCompletedDate)) {
            $scope.contractRiskAsmtForm.riskAssessmentCompletedDate.$setValidity($scope.contractRiskAsmtForm.riskAssessmentCompletedDate.$errors, true);
        }
        $scope.contractRiskAsmtForm.$setPristine();
        riskAssessmentManagementFactory.getRiskAssessmentTemplate(riskAssessment.riskAssessmentTemplateId).then(function(response) {
            if (response.success) {
                $scope.data = response.data;
                $scope.riskAssessmentTemplate = $scope.data;
                $scope.calculateActiveLegalAndContractRiskFactors($scope.riskAssessmentTemplate);
                riskAssessmentManagementFactory.getContractRiskAssessment($scope.contractInfo.contractId, riskAssessment.riskAssessmentId).then(function(response) {
                    if (response.success) {
                        $scope.data = response.data;
                        $scope.riskAssessmentObj = $scope.data;
                        $scope.riskAssessmentObj.riskAssessmentTemplateId = $scope.riskAssessmentTemplate.riskAssessmentTemplateId;
                        $location.hash(scrollLocation);
                        $anchorScroll();
                        $scope.displayLastUpdatedBySection = true;
                        $scope.addEditRiskAmtLabel = "Edit Risk Assessment";
                        if (UserAuth.userHasPermission(['riskAsmtEntryUpdate']) && !($scope.contractInfo.contractStatus.contractStatusId === "3" || $scope.contractInfo.contractStatus.contractStatusId === "4" || $scope.contractInfo.contractStatus.contractStatusId === "5" || $scope.contractInfo.contractStatus.contractStatusId === "13")) {
                            $scope.isAddEditRiskAsmtVisible = true;
                            $scope.displayOnlyRiskAssessment = false;
                        } else {
                            $scope.isAddEditRiskAsmtVisible = false;
                            $scope.displayOnlyRiskAssessment = true;
                        }
                        $scope.isAddNewRiskAssessment = false;
                        $scope.calculateActiveLegalAndContractRiskFactors($scope.riskAssessmentTemplate);
                        for (var index = 0; index < $scope.riskAssessmentObj.otherRiskFactorList.length; index++) {
                            $scope.rowCount = $scope.rowCount + 1;
                            $scope.riskAssessmentObj.otherRiskFactorList[index].number = $scope.rowCount;
                        }
                        $scope.riskAsmtIndex = $scope.riskAssessments.indexOf(riskAssessment);
                        if ($scope.riskAssessmentObj.otherRiskFactorList.length !== 0) {
                            $scope.displayDeleteOtherRiskFactorsButton = true;
                        } else {
                            $scope.displayDeleteOtherRiskFactorsButton = false;
                        }
                        $scope.contractRiskAsmtForm.$setPristine();
                        $scope.oldRiskAssessmentObj = angular.copy($scope.riskAssessmentObj);
                        $scope.errorFromRestService = false;
                        $scope.required = true;
                    } else {
                        $scope.errorMsg = response.error.error.description;
                        $scope.errorFromRestService = true;
                    }
                });

            } else {
                $scope.unableToRetrieveTemplate = true;
            }
        });
        $scope.displayRecordSavedMsg = false;
        $scope.displayRecordDeletedMsg = false;
        $scope.isOtherRiskLevelRequired = false;
        $scope.displayDeleteButton = true;
        $scope.resetSelectAll();
    };

    $scope.editRiskAssessment = function(riskAssessment, scrollLocation) {
        if ($scope.contractRiskAsmtForm.$dirty && !$scope.formNotChanged()) {
            msg = 'There are unsaved changes in the form. Do you want to discard?';
            dialogMessageFactory.getConfirmation(msg).then(function() {
                $scope.InitializeExistingRiskAssessment(riskAssessment, scrollLocation);
            }, function() {});
        } else {
            $scope.InitializeExistingRiskAssessment(riskAssessment, scrollLocation);
        }
    };

    $scope.addOtherRiskFactor = function() {
        $scope.rowCount = $scope.rowCount + 1;
        $scope.otherRiskFactorInfo = {
            number: $scope.rowCount,
            riskFactorName: '',
            otherRiskLevel: '',
            otherRiskWeight: '',
            otherRiskPoint: ''
        };
        $scope.riskAssessmentObj.otherRiskFactorList.push($scope.otherRiskFactorInfo);
        $scope.displayDeleteOtherRiskFactorsButton = true;
        $scope.isOtherRiskLevelRequired = true;
    };

    $scope.chckedIndexes = [];

    $scope.checkedIndex = function(otherRiskFactor) {
        if ($scope.chckedIndexes.indexOf(otherRiskFactor) === -1) {
            $scope.chckedIndexes.push(otherRiskFactor);
            if ($scope.riskAssessmentObj.otherRiskFactorList.length === $scope.chckedIndexes.length) {
                $scope.selectedAll = true;
                $scope.selectOrDeselectLabel = 'Deselect All';
            }
        } else {
            $scope.chckedIndexes.splice($scope.chckedIndexes.indexOf(otherRiskFactor), 1);
            if ($scope.chckedIndexes.length === 0) {
                $scope.resetSelectAll();
            }
        }
    };


    $scope.deleteOtherRiskFactors = function() {
        if ($scope.chckedIndexes.length === 0) {
            msg = 'Please select other risk factor(s) to delete.';
            dialogMessageFactory.getAlertMsg(msg);
        } else {
            msg = 'Do you want to delete the selected other risk factor(s)?. If you select "YES", please make sure to save the Risk Assessment record to permanently delete the other risk factor(s).';
            dialogMessageFactory.getConfirmation(msg).then(function() {
                $scope.selectedAll = false;
                $scope.selectOrDeselectLabel = 'Select All';
                angular.forEach($scope.chckedIndexes, function(value) {
                    $scope.riskAssessmentObj.otherRiskFactorList.splice($scope.riskAssessmentObj.otherRiskFactorList.indexOf(value), 1);
                });
                $scope.calculateActiveLegalAndContractRiskFactors($scope.riskAssessmentTemplate);
                for (var index = 0; index < $scope.riskAssessmentObj.otherRiskFactorList.length; index++) {
                    $scope.rowCount = $scope.rowCount + 1;
                    $scope.riskAssessmentObj.otherRiskFactorList[index].number = $scope.rowCount;
                }
                if ($scope.riskAssessmentObj.otherRiskFactorList.length === 0) {
                    $scope.displayDeleteOtherRiskFactorsButton = false;
                    $scope.isOtherRiskLevelRequired = false;
                    $scope.riskAssessmentObj.otherRiskLevelLookup = null;
                }
                $scope.chckedIndexes = [];
                $scope.calculateOtherRiskScore();
            }, function() {});
        }
    };

    $scope.deleteRiskAssessment = function(riskAssessment) {
        msg = 'Do you want to delete this risk assessment?';
        dialogMessageFactory.getConfirmation(msg).then(function() {
            riskAssessmentManagementFactory.deleteContractRiskAssessment($scope.contractInfo.contractId, riskAssessment.riskAssessmentId).then(function(response) {
                if (response.success) {
                    $scope.displayRecordDeletedMsg = true;
                    $scope.getContractRiskAssessments($scope.contractInfo.contractId, $scope.vm.currentPage, $scope.noOfRecordsPerPage);
                    $scope.isAddEditRiskAsmtVisible = false;
                    $scope.contractRiskAsmtForm.$setPristine();
                } else {
                    $scope.errorMsg = response.error.error.description;
                    $scope.errorFromRestService = true;
                    $scope.displayRecordDeletedMsg = false;
                }
            });
        }, function() {});
    };

    $scope.saveRiskAssessment = function(riskAssessment) {
        $location.hash("");
        $anchorScroll();
        if (riskAssessment.otherRiskLevelLookup == null) {
            riskAssessment.otherRiskLevelLookup = {};
        }
        dialogMessageFactory.showProgressBar();
        if ($scope.isAddNewRiskAssessment) {
            riskAssessmentManagementFactory.createRiskAssessment($scope.contractInfo.contractId, riskAssessment).then(function(response) {
                if (response.success) {
                    $scope.data = response.data;
                    $scope.riskAssessmentObj.riskAssessmentId = $scope.data.resourceId;
                    $scope.displayOnlyRiskAssessment = true;
                    $scope.isAddEditRiskAsmtVisible = false;
                    $scope.displayRecordSavedMsg = true;
                    $scope.errorFromRestService = false;
                    $scope.contractRiskAsmtForm.$setPristine();
                    $scope.getContractRiskAssessments($scope.contractInfo.contractId, $scope.vm.currentPage, $scope.noOfRecordsPerPage);
                    dialogMessageFactory.hideProgressBar();
                } else {
                    $scope.errorMsg = response.error.error.description;
                    $scope.errorFromRestService = true;
                    dialogMessageFactory.hideProgressBar();
                }
            });

        } else {
            riskAssessmentManagementFactory.updateRiskAssessment($scope.contractInfo.contractId, riskAssessment.riskAssessmentId, riskAssessment).then(function(response) {
                if (response.success) {
                    $scope.data = response.data;
                    $scope.displayOnlyRiskAssessment = true;
                    $scope.isAddEditRiskAsmtVisible = false;
                    $scope.displayRecordSavedMsg = true;
                    $scope.errorFromRestService = false;
                    $scope.contractRiskAsmtForm.$setPristine();
                    $scope.getContractRiskAssessments($scope.contractInfo.contractId, $scope.vm.currentPage, $scope.noOfRecordsPerPage);
                    dialogMessageFactory.hideProgressBar();
                } else {
                    $scope.errorMsg = response.error.error.description;
                    $scope.errorFromRestService = true;
                    dialogMessageFactory.hideProgressBar();
                }
            });
        }
    };

    $scope.selectAllRiskFactors = function() {
        $scope.selectedAll = !$scope.selectedAll;
        if ($scope.selectedAll) {
            $scope.selectOrDeselectLabel = 'Deselect All';
        } else {
            $scope.selectOrDeselectLabel = 'Select All';
        }
        angular.forEach($scope.riskAssessmentObj.otherRiskFactorList, function(item) {
            item.checked = $scope.selectedAll;
            $scope.checkedIndex(item);
        });
    };

    $scope.calculateOtherRiskScore = function() {
        $scope.itemOtherRiskScore = 0;
        angular.forEach($scope.riskAssessmentObj.otherRiskFactorList, function(value, key) {
            if (!angular.isUndefined(value.otherRiskLevel) && !angular.isUndefined(value.otherRiskWeight)) {
                $scope.itemOtherRiskScore = $scope.itemOtherRiskScore + value.otherRiskLevel * value.otherRiskWeight;
                $scope.riskAssessmentObj.otherRiskFactorList[key].otherRiskPoint = $scope.riskAssessmentObj.otherRiskFactorList[key].otherRiskLevel * $scope.riskAssessmentObj.otherRiskFactorList[key].otherRiskWeight;
            }
        });
        $scope.riskAssessmentObj.otherRiskScore = $scope.itemOtherRiskScore;
    };

    $scope.resetSelectAll = function() {
        $scope.selectedAll = false;
        $scope.selectOrDeselectLabel = 'Select All';
        $scope.chckedIndexes = [];
    };

    $scope.cancelRiskAssessment = function() {
        msg = 'There are unsaved changes in the form. Do you want to discard?';
        $scope.displayRecordSavedMsg = false;
        if ($scope.isAddNewRiskAssessment) {
            if ($scope.contractRiskAsmtForm.$dirty && !$scope.formNotChanged()) {
                dialogMessageFactory.getConfirmation(msg).then(function() {
                    $scope.riskAssessmentObj = {};
                    $scope.contractRiskAsmtForm.$setPristine();
                    $scope.isAddEditRiskAsmtVisible = false;
                    $scope.displayOnlyRiskAssessment = false;
                    $scope.resetSelectAll();
                    $location.hash('');
                    $anchorScroll();
                }, function() {});
            } else {
                $scope.riskAssessmentObj = {};
                $scope.resetSelectAll();
                $location.hash('');
                $anchorScroll();
                $scope.contractRiskAsmtForm.$setPristine();
                $scope.isAddEditRiskAsmtVisible = false;
                $scope.displayOnlyRiskAssessment = false;
            }
        } else {
            if ($scope.contractRiskAsmtForm.$dirty && !$scope.formNotChanged()) {
                dialogMessageFactory.getConfirmation(msg).then(function() {
                    $scope.resetSelectAll();
                    $scope.contractRiskAsmtForm.$setPristine();
                    $scope.isAddEditRiskAsmtVisible = false;
                    $scope.displayOnlyRiskAssessment = false;
                    $location.hash('');
                    $anchorScroll();
                }, function() {});
            } else {
                $scope.resetSelectAll();
                $location.hash('');
                $anchorScroll();
                $scope.contractRiskAsmtForm.$setPristine();
                $scope.isAddEditRiskAsmtVisible = false;
                $scope.displayOnlyRiskAssessment = false;
            }
        }
    };

    $scope.setNoOfRecordsPage = function(noOfRecordsPerPage) {
        $scope.vm.currentPage = 1;
        $scope.noOfRec = noOfRecordsPerPage;
        $scope.getContractRiskAssessments($scope.contractInfo.contractId, $scope.vm.currentPage, $scope.noOfRecordsPerPage);
    };

    $scope.retrievePaginatedRiskAssessments = function() {
        $scope.getContractRiskAssessments($scope.contractInfo.contractId, $scope.vm.currentPage, $scope.noOfRec);
    };

    $scope.calculateActiveLegalAndContractRiskFactors = function(riskAssessmentTemplate) {
        $scope.activeLegalTemplates = 0;
        $scope.activeContractTemplates = 0;
        for (var index = 0; index < riskAssessmentTemplate.riskAssessmentTemplateLegals.length; index++) {
            if (riskAssessmentTemplate.riskAssessmentTemplateLegals[index].riskFactorStatus === true) {
                $scope.activeLegalTemplates = $scope.activeLegalTemplates + 1;
            }
        }
        for (index = 0; index < riskAssessmentTemplate.riskAssessmentTemplateContracts.length; index++) {
            if (riskAssessmentTemplate.riskAssessmentTemplateContracts[index].riskFactorStatus === true) {
                $scope.activeContractTemplates = $scope.activeContractTemplates + 1;
            }
        }
        $scope.rowCount = $scope.activeLegalTemplates + $scope.activeContractTemplates;
    };
    
    $scope.validateRiskAssessmentDate = function(){
    	riskAsmtEntryFactory.validateRiskAssessmentDate($scope);
    }
    
    $scope.getCreatedDate = function(){
    	return riskAsmtEntryFactory.getCreatedDate($scope);
    }

    $scope.validateFiscalYear = function() {
        if (!angular.isUndefined($scope.riskAssessmentObj.riskAssessmentDate) && $scope.riskAssessmentObj.riskAssessmentDate !== '') {
            var riskAssessmentDate = new Date($scope.riskAssessmentObj.riskAssessmentDate);
            if (riskAssessmentDate < new Date('01/01/1920') || riskAssessmentDate > new Date('12/31/2199')) {
                $scope.invalidRiskAssessmentDate = true;
                $scope.contractRiskAsmtFormB.riskAssessmentCompletedDate.$setValidity($scope.contractRiskAsmtFormB.riskAssessmentCompletedDate.$errors, false);
                $scope.contractRiskAsmtFormB.fiscalYear.$setValidity($scope.contractRiskAsmtFormB.fiscalYear.$errors, true);
            } else {
                $scope.invalidRiskAssessmentDate = false;
                $scope.contractRiskAsmtFormB.riskAssessmentCompletedDate.$setValidity($scope.contractRiskAsmtFormB.riskAssessmentCompletedDate.$errors, true);
                if (!angular.isUndefined($scope.riskAssessmentObj.fiscalYear) && $scope.riskAssessmentObj.fiscalYear !== "") {
                    var riskAssessmentYear = riskAssessmentDate.getFullYear();
                    var fiscalYear = Number($scope.riskAssessmentObj.fiscalYear);
                    if (fiscalYear > (riskAssessmentYear + 1) || fiscalYear < (riskAssessmentYear - 1)) {
                        $scope.invalidRiskAssessmentFiscalYear = true;
                        $scope.contractRiskAsmtFormB.fiscalYear.$setValidity($scope.contractRiskAsmtFormB.fiscalYear.$errors, false);
                    } else {
                        $scope.invalidRiskAssessmentFiscalYear = false;
                        $scope.contractRiskAsmtFormB.fiscalYear.$setValidity($scope.contractRiskAsmtFormB.fiscalYear.$errors, true);
                    }
                } else {
                    $scope.invalidRiskAssessmentFiscalYear = false;
                    //$scope.contractRiskAsmtFormB.riskAssessmentFiscalYear.$setValidity($scope.contractRiskAsmtForm.riskAssessmentFiscalYear.$errors, false);
                }
            }
        } else {
            $scope.resetFormErrorMessages();
        }
    };

    $scope.validateOtherRiskLevel = function() {
        if ($scope.riskAssessmentObj.otherRiskLevelLookup == null) {
            $scope.isOtherRiskLevelRequired = true;
        } else {
            $scope.isOtherRiskLevelRequired = false;
        }
    };

    $scope.resetFormErrorMessages = function() {
        $scope.invalidRiskAssessmentDate = false;
        $scope.invalidRiskAssessmentFiscalYear = false;
    };

    var routeChangeOff = $scope.$on('$stateChangeStart',
        function(event, toState) {
            var destination = toState.name;
            event.preventDefault();
            msg = 'There are unsaved changes in the form. Do you want to discard?';
            if ($scope.contractRiskAsmtForm.$dirty && !$scope.formNotChanged()) {
                dialogMessageFactory.getConfirmation(msg).then(function() {
                    routeChangeOff();
                    $state.go(destination);
                }, function() {
                    $rootScope.setChildTab('administration_contract_management_risk_assessment_entry');
                });
            } else {
                routeChangeOff();
                $state.go(destination);
            }

        });

    $scope.formNotChanged = function() {
        return formUtilFactory.trueEqual($scope.oldRiskAssessmentObj, $scope.riskAssessmentObj);
    };
	
    //New risk assessment 2 functions below
    $scope.initializeRiskAssessmentModel = function(riskAssessmentTemplate){
		
		$scope.riskAssessmentObj.riskAssessmentTemplateId = riskAssessmentTemplate.riskAssessmentTemplateId;
		for(var i=0; i < riskAssessmentTemplate.riskRangeTypes.length; i++){
			for(var j=0; j < riskAssessmentTemplate.riskRangeTypes[i].riskFactors.length; j++){
				$scope.riskAssessmentObj.riskRangeTypes[i].riskFactors[j].riskRangeTypeId = riskAssessmentTemplate.riskRangeTypes[i].riskRangeTypeId;
				$scope.riskAssessmentObj.riskRangeTypes[i].riskFactors[j].riskFactorId = riskAssessmentTemplate.riskRangeTypes[i].riskFactors[j].riskFactorId;
			}
		}
	};
	
	$scope.createRiskAssessmentModelCalculatedFields = function(riskAssessment){
		var riskRangeTypes = riskAssessment.riskRangeTypes;
		
		riskAssessment.createBaseLineRiskRanges = function (){
			var baseLineRiskRangesText = [];

			for(var j=0; j < riskRangeTypes[0].riskRangeTypeRanges.length; j++){
				baseLineRiskRangesText[j] = {
													level : "",
													min : 0,
													max : 0
												};
				
			}
			
			for(var i=0; i < riskRangeTypes.length; i++){
				
				for(var j=0; j < riskRangeTypes[i].riskRangeTypeRanges.length; j++){
					baseLineRiskRangesText[j].level = riskRangeTypes[i].riskRangeTypeRanges[j].riskLevel.levelDesc;
					baseLineRiskRangesText[j].min += riskRangeTypes[i].riskRangeTypeRanges[j].min;
					baseLineRiskRangesText[j].max += riskRangeTypes[i].riskRangeTypeRanges[j].max;
					
				}
				
				/*risk ranges produce a gap when summing risk range risk scores example:
				   Low = 3-6    Medium = 7-10    High = 11-15
				   Low = 3-7    Medium = 8-12    High = 13-17
				total:  6-13			15-22          24-32 <-- notice 13 jumps to 15 and 22 to 24
				this loop adjusts to produce correct result of
				Low = 6-13    Medium = 14-22    High = 23-32 according to legacy risk Assessment risk calculations
				*/
				
				for(var k=1; k < riskRangeTypes[i].riskRangeTypeRanges.length; k++){
					baseLineRiskRangesText[k].min = baseLineRiskRangesText[k-1].max + 1;
				}
			}
			
			riskAssessment.baseLineRiskRanges = baseLineRiskRangesText;
			
		};
		
		riskAssessment.baseLineRiskRangesText = function (){
			
			var riskRangesText = "";
			var riskRanges = riskAssessment.baseLineRiskRanges;
			
			for(var i=0; i < riskRanges.length; i++){
				riskRangesText += riskRanges[i].level + ' = ' + riskRanges[i].min + '-' + riskRanges[i].max + ' ';
			}
			
			return riskRangesText;
		};
		
		riskAssessment.baseLineRiskRangeText = function(){
			
			var riskRanges = riskAssessment.baseLineRiskRanges;
				
			return riskRanges[0].min + ' - ' + riskRanges[riskRanges.length-1].max;
		};
			
		riskAssessment.baseLineRiskLevelScore = 
			function(){
				var sum = 0;
				
				for(var i=0; i < riskRangeTypes.length; i++){
					for(var j=0; j < riskRangeTypes[i].riskFactors.length; j++){
						if(riskRangeTypes[i].riskFactors[j].riskFactorLevel == undefined){
							if(riskRangeTypes[i].riskFactors[j].score != undefined){
								sum = sum + riskRangeTypes[i].riskFactors[j].score * riskRangeTypes[i].riskFactors[j].weightMultiplier;
							}
						}
						else{
							sum = sum + riskRangeTypes[i].riskFactors[j].riskFactorLevel.score * riskRangeTypes[i].riskFactors[j].weightMultiplier;
						}
					}
				}
				
			return sum;
		};
				
		riskAssessment.baseLineRiskLevel = 
			function(){
				
				var riskLevel = "";
				var riskScore = riskAssessment.baseLineRiskLevelScore();
				var ranges = riskAssessment.baseLineRiskRanges;
				
				for(var i=0; i < ranges.length; i++){
					if(riskScore >= ranges[i].min && riskScore <= ranges[i].max){
						riskLevel = ranges[i].level;
						break;
					}
				}
				
				return riskLevel;
		};
		
		for(var i=0; i < riskAssessment.riskRangeTypes.length; i++){
			
			for(var j=0; j < riskAssessment.riskRangeTypes[i].riskFactors.length; j++){
				
				var riskFactor = riskAssessment.riskRangeTypes[i].riskFactors[j];
				//create riskFactor riskPoint
				riskAssessment.riskRangeTypes[i].riskFactors[j].riskPoints = 
					function(score, weightMultiplier){
							return (score == undefined || weightMultiplier == undefined) ? 0 : score * weightMultiplier;
					};
			}
			
			for(var j=0; j < riskAssessment.riskRangeTypes[i].riskRangeTypeRanges.length; j++){
				//create risk range riskRangeText
				riskAssessment.riskRangeTypes[i].riskRangeText = 
					function(ranges){
						return ranges[0].min + ' - ' + ranges[ranges.length-1].max;
					};
				//create risk range riskRangesText
				riskAssessment.riskRangeTypes[i].riskRangesText = 
					function(ranges){
						var rangesText = "";
						
						for(var idx=0; idx < ranges.length; idx++){
							rangesText += ranges[idx].riskLevel.levelDesc + ' = ' + ranges[idx].min + '-' + ranges[idx].max + '  ';
						}
						
						return rangesText;
					};
			}
		}
	};
	
	$scope.getContractBaseEvaluation = function() {
		riskAssessmentManagementFactory.getContractBaseEvaluation($scope.contractNumber).then(function(response) {
			if (response.success) {
				$scope.contractBaseEvaluationReady = true;
				$scope.contractBaseEvaluation = response.data;
				$scope.setDollarAmountOfContract();
				
			}
		});
	};
	
	$scope.getContractRiskAssessmentsB = function(contractId, pageNumber, noOfRecordsPerPage) {
        riskAssessmentManagementFactory.getContractRiskAssessments(contractId, pageNumber - 1, noOfRecordsPerPage).then(function(response) {
            if (response.success) {
                $scope.data = response.data;
				$scope.riskAssessments = $scope.data._embedded.riskAssessedContractList;
				$scope.totalItems = $scope.data._embedded.riskAssessedContractList.length;
				
				for(var i=0; i < $scope.riskAssessments.length; i++){
					if(parseFloat($scope.riskAssessments[i].riskAssessmentTemplateVersion) >= 2){
						$scope.createRiskAssessmentModelCalculatedFields($scope.riskAssessments[i]);
						$scope.riskAssessments[i].createBaseLineRiskRanges();
					}
				}
				
                $scope.showNoRecordsMessage = false;
                $scope.displayPagination = true;
            } else {
                $scope.riskAssessments = [];
                $scope.totalItems = 0;
                $scope.showNoRecordsMessage = true;

                var userAgency = JSON.parse(localSessionFactory.getUserAgency());
                if (userAgency.agencyId.localeCompare("2") === 0) {
                    $scope.isNoDFPSRecordsMessageDisabled = false
                    $scope.contractnumber = contractId;
                }

                $scope.displayPagination = false;
                if ($scope.displayRecordDeletedMsg && $scope.vm.currentPage - 1 > 0) {
                    $scope.vm.currentPage = $scope.vm.currentPage - 1;
                    $scope.getContractRiskAssessmentsB($scope.vm.currentPage, $scope.noOfRecordsPerPage);
                }
            }
        });
    };
	
	$scope.getContractRiskAssessmentsB($scope.vm.currentPage, $scope.noOfRecordsPerPage);
    
    $scope.InitializeNewRiskAssessmentB = function(scrollLocation) {
        $scope.contractRiskAsmtFormB.$setPristine();
        $scope.riskAssessmentDateGreaterThanToday = false;
		
		riskAssessmentManagementFactory.getRiskAssessmentTemplateB().then(function(response) {
            if (response.success) {
				
				$scope.addEditRiskAmtLabel = "Add Risk Assessment";
                $scope.riskAssessmentObj = response.data;
				$scope.riskAssessmentObj.createdBy = "";
				$scope.riskAssessmentObj.createdDate = "";
				$scope.riskAssessmentObj.updatedBy = "";
				$scope.riskAssessmentObj.updatedDate = "";
				$scope.initializeRiskAssessmentModel($scope.riskAssessmentObj);
				$scope.createRiskAssessmentModelCalculatedFields($scope.riskAssessmentObj);
				$scope.riskAssessmentObj.createBaseLineRiskRanges();
				$scope.setRiskFactorRiskLevels();
									
				for(var i=0; i < response.data.length; i++){
					$scope.riskRangeTypeTotalScore.push(0);
				}
				
				$scope.isAddEditRiskAsmtVisibleB = true;
				$scope.isEditRiskAssessment = false;
				$scope.isAddRiskAssessment = true;
            }
        });
		$scope.isAddEditRiskAsmtVisibleB = true;
		
        $scope.displayRecordSavedMsg = false;
        $scope.showNoRecordsMessage = false;
        $scope.displayRecordDeletedMsg = false;
        $scope.errorFromRestService = false;
        $scope.displayDeleteButton = false;
        $scope.required = true;
        //$scope.resetSelectAll();
    };    
    
    $scope.setAssessedFactorProperties = function(riskRangeTypeId, riskFactorId, riskRange, riskFactor, riskFactorLevel){
		
		$scope.riskAssessmentObj.riskRangeTypes[riskRangeTypeId].riskFactors[riskFactorId].riskFactorLevelId = riskFactorLevel.riskFactorLevelId;
		$scope.riskAssessmentObj.riskRangeTypes[riskRangeTypeId].riskFactors[riskFactorId].riskFactorLevel = riskFactorLevel;

	};
	
	$scope.getBaseLineRiskRanges = function(riskRangeType){
		for(var i=0; i < riskRangeType.riskRangeTypeRanges.length; i++){
			$scope.baseLineRiskRangeTypeRanges[i].level = riskRangeType.riskRangeTypeRanges[i].level;
			$scope.baseLineRiskRangeTypeRanges[i].min += riskRangeType.riskRangeTypeRanges[i].min;
			$scope.baseLineRiskRangeTypeRanges[i].max += riskRangeType.riskRangeTypeRanges[i].max;
		}
		
		/*risk ranges produce a gap when summing risk range risk scores example:
		   Low = 3-6    Medium = 7-10    High = 11-15
		   Low = 3-7    Medium = 8-12    High = 13-17
		total:  6-13			15-22          24-32 <-- notice 13 jumps to 15 and 22 to 24
        this loop adjusts to produce correct result of
		Low = 6-13    Medium = 14-22    High = 23-32 according to legacy risk Assessment risk calculations
		*/
		for(var i=1; i < riskRangeType.riskRangeTypeRanges.length; i++){
			$scope.baseLineRiskRangeTypeRanges[i].min = $scope.baseLineRiskRangeTypeRanges[i-1].max + 1;
		}
	};	
    
	$scope.getRiskRangeTotalScore = function(riskRangeIndex, riskFactors) {
		var sum = 0;
		
		console.log(riskFactors);
		
		for(var i=0; i < riskFactors.length; i++){
			if(riskFactors[i].riskFactorLevel == undefined){
				if(riskFactors[i].score != undefined){
					sum = sum + riskFactors[i].score * riskFactors[i].weightMultiplier;
				}
			}
			else{
				sum = sum + riskFactors[i].riskFactorLevel.score * riskFactors[i].weightMultiplier;
			}
		}
		
		$scope.riskRangeTypeTotalScore[riskRangeIndex] = sum;
	};	
	
	$scope.getRiskRangeRiskLevel = function(riskRangeIndex, riskRange){
		
		if(riskRange.riskRangeTypeRanges != undefined){
			
			var riskLevel = "";
			var riskRangeScore = $scope.riskRangeTypeTotalScore[riskRangeIndex];
			
			for(var i=0; i < riskRange.riskRangeTypeRanges.length; i++){
				var riskRangeTypeRange = riskRange.riskRangeTypeRanges[i];
				
				if(riskRangeScore >= riskRangeTypeRange.min && riskRangeScore <= riskRangeTypeRange.max){
						
					riskLevel = riskRangeTypeRange.riskLevel.levelDesc;
					break;
				}
			}
			
			
			
			$scope.riskRangeTypeRiskLevel[riskRangeIndex] = riskLevel;
		}
	};
	
	$scope.editRiskRangeTotalScore = function(riskRangeIndex, riskFactor, riskFactorLevel){

		var sum = $scope.riskRangeTypeTotalScore[riskRangeIndex];
		
		sum -= riskFactor.weightMultiplier * riskFactor.riskFactorLevel.score;
		sum += riskFactor.weightMultiplier * riskFactorLevel.score;
		
		riskFactor.riskFactorLevel = riskFactorLevel;
	
		$scope.riskRangeTypeTotalScore[riskRangeIndex] = sum;
	};
	
    $scope.showAddRiskAsmtPanelB = function(scrollLocation) {
        if ($scope.contractRiskAsmtFormB.$dirty && !$scope.formNotChanged()) {
            msg = 'There are unsaved changes in the form. Do you want to discard?';
            dialogMessageFactory.getConfirmation(msg).then(function() {
                $scope.InitializeNewRiskAssessmentB(scrollLocation);
            }, function() {});
        } else {
            $scope.InitializeNewRiskAssessmentB(scrollLocation);
        }
    };	
    
    $scope.InitializeExistingRiskAssessmentB = function(riskAssessment, scrollLocation) {
        $scope.required = false;
        $scope.invalidRiskAssessmentFiscalYear = false;
        $scope.riskAssessmentDateGreaterThanToday = false;
		$scope.displayOnlyRiskAssessment = false;
		$scope.isAddEditRiskAsmtVisible = false;
		
        if (!angular.isUndefined($scope.contractRiskAsmtFormB.riskAssessmentFiscalYear)) {
            $scope.contractRiskAsmtFormB.riskAssessmentFiscalYear.$setValidity($scope.contractRiskAsmtFormB.riskAssessmentFiscalYear.$errors, true);
        }
        $scope.invalidRiskAssessmentDate = false;
        if (!angular.isUndefined($scope.contractRiskAsmtFormB.riskAssessmentCompletedDate)) {
            $scope.contractRiskAsmtFormB.riskAssessmentCompletedDate.$setValidity($scope.contractRiskAsmtFormB.riskAssessmentCompletedDate.$errors, true);
        }
        $scope.contractRiskAsmtFormB.$setPristine();
		
		riskAssessmentManagementFactory.getContractRiskAssessmentB(riskAssessment.riskAssessmentId).then(function(response) {
			
			if (response.success) {
				
				$scope.addEditRiskAmtLabel = "Edit Risk Assessment";
				
				if($scope.contractClosed) {
					$scope.addEditRiskAmtLabel = "Risk Assessment";
				}
				
				$scope.riskAssessmentObj = response.data;
				$scope.isAddEditRiskAsmtVisibleB = true;
				$scope.isAddRiskAssessment = false;
				$scope.isEditRiskAssessment = true;
				$scope.baseLineRiskLevelScore = 0;
				$scope.createRiskAssessmentModelCalculatedFields($scope.riskAssessmentObj);
				$scope.riskAssessmentObj.createBaseLineRiskRanges();
			}
		});

        $scope.displayRecordSavedMsg = false;
        $scope.displayRecordDeletedMsg = false;
        $scope.isOtherRiskLevelRequired = false;
        $scope.displayDeleteButton = true;
        //$scope.resetSelectAll();
    };
    
    $scope.editRiskAssessmentB = function(riskAssessment, scrollLocation) {
        if ($scope.contractRiskAsmtFormB.$dirty && !$scope.formNotChanged()) {
            msg = 'There are unsaved changes in the form. Do you want to discard?';
            dialogMessageFactory.getConfirmation(msg).then(function() {
				if(riskAssessment.riskAssessmentTemplateVersion < 2){
					$scope.InitializeExistingRiskAssessment(riskAssessment, scrollLocation);
				}
				else{
					$scope.InitializeExistingRiskAssessmentB(riskAssessment, scrollLocation);
				}
            }, function() {});
        } else {
            if(riskAssessment.riskAssessmentTemplateVersion < 2){
				$scope.InitializeExistingRiskAssessment(riskAssessment, scrollLocation);
			}
			else{
				$scope.InitializeExistingRiskAssessmentB(riskAssessment, scrollLocation);
			}
        }
    };
    
    $scope.deleteRiskAssessmentB = function(riskAssessment) {
        msg = 'Do you want to delete this risk assessment?';
        dialogMessageFactory.getConfirmation(msg).then(function() {
            riskAssessmentManagementFactory.deleteContractRiskAssessmentB(riskAssessment.riskAssessmentId).then(function(response) {
                if (response.success) {
                    $scope.displayRecordDeletedMsg = true;
                    $scope.getContractRiskAssessmentsB($scope.vm.currentPage, $scope.noOfRecordsPerPage);
                    $scope.isAddEditRiskAsmtVisibleB = false;                    
                    $scope.contractRiskAsmtFormB.$setPristine();
                } else {
                    $scope.errorMsg = response.error.error.description;
                    $scope.errorFromRestService = true;
                    $scope.displayRecordDeletedMsg = false;
                }
            });
        }, function() {});
    };
    
    $scope.saveRiskAssessmentB = function(riskAssessment) {
        $location.hash("");
        $anchorScroll();
        
        var user_info = JSON.parse(localSessionFactory.getUser());
        riskAssessment.updatedBy = user_info.userName;
		
		dialogMessageFactory.showProgressBar();
        if ($scope.isAddRiskAssessment) {
			riskAssessment.createdBy = user_info.userName;
            riskAssessmentManagementFactory.createRiskAssessmentB(riskAssessment).then(function(response) {
                if (response.success) {
					$scope.addEditRiskAmtLabel = "";
                    $scope.data = response.data;
                    $scope.isAddEditRiskAsmtVisibleB = false;
                    $scope.displayRecordSavedMsg = true;
                    $scope.errorFromRestService = false;
                    $scope.displayLastUpdatedBySection = true;
                    riskAssessmentManagementFactory.getContractRiskAssessmentB(response.data.riskAssessmentId).then(function(response) {
                        $scope.riskAssessmentObj = response.data;
						$scope.isAddEditRiskAsmtVisibleB = true;
						$scope.isAddRiskAssessment = false;
						$scope.isEditRiskAssessment = true;
						$scope.baseLineRiskLevelScore = 0;
						$scope.createRiskAssessmentModelCalculatedFields($scope.riskAssessmentObj);
						$scope.riskAssessmentObj.createBaseLineRiskRanges();
                    });
					
                    $scope.contractRiskAsmtFormB.$setPristine();
                    $scope.getContractRiskAssessmentsB($scope.vm.currentPage, $scope.noOfRecordsPerPage);
                } else {
                    $scope.errorMsg = response.error.error.description;
                    $scope.errorFromRestService = true;
                }

                dialogMessageFactory.hideProgressBar();
            });
        } else {
            riskAssessmentManagementFactory.updateRiskAssessmentB(riskAssessment.riskAssessmentId, riskAssessment).then(function(response) {
                if (response.success) {
					$scope.addEditRiskAmtLabel = "";
                    $scope.data = response.data;
                    $scope.isAddEditRiskAsmtVisibleB = false;
                    $scope.displayRecordSavedMsg = true;
                    $scope.errorFromRestService = false;
                    riskAssessmentManagementFactory.getContractRiskAssessmentB(response.data.riskAssessmentId).then(function(response) {
                        $scope.riskAssessmentObj = response.data;
						$scope.isAddEditRiskAsmtVisibleB = true;
						$scope.isAddRiskAssessment = false;
						$scope.isEditRiskAssessment = true;
						$scope.baseLineRiskLevelScore = 0;
						$scope.createRiskAssessmentModelCalculatedFields($scope.riskAssessmentObj);
						$scope.riskAssessmentObj.createBaseLineRiskRanges();
                    });
                    $scope.contractRiskAsmtFormB.$setPristine();
                    $scope.getContractRiskAssessmentsB($scope.vm.currentPage, $scope.noOfRecordsPerPage);
                    dialogMessageFactory.hideProgressBar();
                } else {
                    $scope.errorMsg = response.error.error.description;
                    $scope.errorFromRestService = true;
                    dialogMessageFactory.hideProgressBar();
                }
            });
        }
    };
    
    $scope.cancelRiskAssessmentB = function() {
        msg = 'There are unsaved changes in the form. Do you want to discard?';
        $scope.displayRecordSavedMsg = false;
        if ($scope.isAddRiskAssessment) {
            if ($scope.contractRiskAsmtFormB.$dirty && !$scope.formNotChanged()) {
                dialogMessageFactory.getConfirmation(msg).then(function() {
                    $scope.riskAssessmentObj = {};
					$scope.isAddRiskAssessment = false;
                    $scope.isOtherRiskLevelRequired = false;
                    $scope.contractRiskAsmtFormB.$setPristine();
                    $scope.isAddEditRiskAsmtVisibleB = false;
                    $scope.displayOnlyRiskAssessment = false;
                    //$scope.resetSelectAll();
                    $location.hash('');
                    $anchorScroll();
                }, function() {});
            } else {
				$scope.isAddRiskAssessment = false;
                $scope.riskAssessmentObj = {};
                //$scope.resetSelectAll();
                $location.hash('');
                $anchorScroll();
                $scope.contractRiskAsmtFormB.$setPristine();
                $scope.isAddEditRiskAsmtVisibleB = false;
                $scope.displayOnlyRiskAssessment = false;
            }
        } else {
            if ($scope.contractRiskAsmtFormB.$dirty && !$scope.formNotChanged()) {
                dialogMessageFactory.getConfirmation(msg).then(function() {
					$scope.isEditRiskAssessment = false;
                  //  $scope.resetSelectAll();
                    $scope.isOtherRiskLevelRequired = false;
                    $scope.contractRiskAsmtFormB.$setPristine();
                    $scope.isAddEditRiskAsmtVisibleB = false;
                    $scope.displayOnlyRiskAssessment = false;
                    $location.hash('');
                    $anchorScroll();
                }, function() {});
            } else {
				$scope.isEditRiskAssessment = false;
                //$scope.resetSelectAll();
                $location.hash('');
                $anchorScroll();
                $scope.contractRiskAsmtFormB.$setPristine();
                $scope.isAddEditRiskAsmtVisibleB = false;
                $scope.displayOnlyRiskAssessment = false;
            }
        }
    };
	
	$scope.setRiskFactorRiskLevels = function(){
		
		var isRiskLevel = false;
		
		for(var i=0; i < $scope.riskAssessmentObj.riskRangeTypes.length; i++){
			var riskRangeIndex = i;
			for(var j=0; j < $scope.riskAssessmentObj.riskRangeTypes[i].riskFactors.length; j++){
				var riskFactor = $scope.riskAssessmentObj.riskRangeTypes[i].riskFactors[j];
				var riskFactorIndex = j;
				
				for(var k=0; k < riskFactor.riskFactorLevels.length; k++){
					var riskFactorLevel = riskFactor.riskFactorLevels[k];
				
					if(riskFactor.factorDesc.includes("Number of Active Contracts with HHS")){
						if(riskFactorLevel.riskLevelName.includes("Less than 5 contracts") || 
							riskFactorLevel.riskLevelName.includes("6 to 14 contracts")  ||
							riskFactorLevel.riskLevelName.includes("More than 15 contracts")){
						
							isRiskLevel = $scope.setNumberOfActiveContractRiskLevel(riskFactorLevel, 
										riskRangeIndex, riskFactorIndex);
						}					
					}
					
					if(riskFactor.factorDesc.includes("Dollar Amount of Contract")){
						if(riskFactorLevel.riskLevelName.includes("Less than $500,000") ||
							riskFactorLevel.riskLevelName.includes("$500,000 to $1 Million") ||
							riskFactorLevel.riskLevelName.includes("More than $1 Million")){
						
							isRiskLevel = $scope.setDollarAmountContractRiskLevel(riskFactorLevel, 
									riskRangeIndex, riskFactorIndex);
						}
					}
					
					if(isRiskLevel){
						$scope.getRiskRangeTotalScore(riskRangeIndex, $scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors);
						$scope.setAssessedFactorProperties(riskRangeIndex, riskFactorIndex, 
										$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex], 
										$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex], 
										riskFactorLevel);
						isRiskLevel = false;
					}
				}
			}
		}
	};
	
	$scope.setNumberOfActiveContractRiskLevel = function(riskFactorLevel, riskRangeIndex, riskFactorIndex){
		
		var isRiskLevel = false;
		
		if(riskFactorLevel.riskLevelName.includes("Less than 5 contracts") && $scope.contractBaseEvaluation.activeCntrt <= 5){
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].riskFactorLevelId = riskFactorLevel.riskFactorLevelId;
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].score = riskFactorLevel.score;
			isRiskLevel = true;
		} 
		else if(riskFactorLevel.riskLevelName.includes("6 to 14 contracts") && $scope.contractBaseEvaluation.activeCntrt >= 5 &&
		          $scope.contractBaseEvaluation.activeCntrt <= 14) {
		    $scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].riskFactorLevelId = riskFactorLevel.riskFactorLevelId;
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].score = riskFactorLevel.score;
			isRiskLevel = true;
		} 
		else if(riskFactorLevel.riskLevelName.includes("More than 15 contracts") && $scope.contractBaseEvaluation.activeCntrt > 14){
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].riskFactorLevelId = riskFactorLevel.riskFactorLevelId;
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].score = riskFactorLevel.score;
			isRiskLevel = true;
		}
		
		return isRiskLevel;

	};
	
	$scope.setDollarAmountContractRiskLevel = function(riskFactorLevel, riskRangeIndex, riskFactorIndex){
		
		var isRiskLevel = false;
		
		if(riskFactorLevel.riskLevelName.includes("Less than $500,000") && $scope.contractBaseEvaluation.dollarAmountOfContract < 500000){
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].riskFactorLevelId = riskFactorLevel.riskFactorLevelId;
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].score = riskFactorLevel.score;
			isRiskLevel = true;
		} 
		else if(riskFactorLevel.riskLevelName.includes("$500,000 to $1 Million") &&  $scope.contractBaseEvaluation.dollarAmountOfContract >= 500000 &&
		    $scope.contractBaseEvaluation.dollarAmountOfContract >= 1000000){
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].riskFactorLevelId = riskFactorLevel.riskFactorLevelId;
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].score = riskFactorLevel.score;
			isRiskLevel = true;
		} 
		else if(riskFactorLevel.riskLevelName.includes("More than $1 Million") && $scope.contractBaseEvaluation.dollarAmountOfContract > 1000000){
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].riskFactorLevelId = riskFactorLevel.riskFactorLevelId;
			$scope.riskAssessmentObj.riskRangeTypes[riskRangeIndex].riskFactors[riskFactorIndex].score = riskFactorLevel.score;
			isRiskLevel = true;
		}
		
		return isRiskLevel;
	};
	
	$scope.setDollarAmountOfContract = function(){
		
		if($scope.contractBaseEvaluation.maxContractAmount == 0){
			$scope.contractBaseEvaluation.dollarAmountOfContract = $scope.contractBaseEvaluation.initialEstTotalCntrtAmt;
		} 
		else if ($scope.contractBaseEvaluation.maxContractAmount != 0 && 
		           $scope.contractBaseEvaluation.maxContractAmount > $scope.contractBaseEvaluation.initialEstTotalCntrtAmt){
			$scope.contractBaseEvaluation.dollarAmountOfContract = $scope.contractBaseEvaluation.maxContractAmount
		} 
		else {
			$scope.contractBaseEvaluation.dollarAmountOfContract = $scope.contractBaseEvaluation.initialEstTotalCntrtAmt;
		}
	};	
});