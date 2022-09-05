% ------------------------
%       fn_Validation
% ------------------------
% Authored by Jordan Pitt 5/7/21
%
%
% Code to run validation tests in a formatted way
%
%
%   Inputs :
%         TestInformation is a cell array of structures which have attributes:
%                   function - a matlab function
%                   inputs - a cell array of inputs to the function
%                   metric - a measure function M(x), where M(x) = 0 if x is the
%                   'correct' answer
%                   tolerance - a tolerance of the measure function, below which the
%                   validation test is deemed a success.
%
%
%   Outputs :
%          Valid a logical value, true if all tests are successes, false otherwise. 

function Valid = fn_Validation(TestInformation)

  
  for i = 1:length(TestInformation)
      Result = TestInformation{i}.function(TestInformation{i}.inputs{:});
      Measure = TestInformation{i}.metric(Result);
      Success = abs(Measure) < TestInformation{i}.tolerance;

      cprintf('Text', ['Commence Test - ', TestInformation{i}.name ,'\n']); 
      cprintf('Text', ['Tolerance Value - ', num2str(TestInformation{i}.tolerance),'\n']); 
      cprintf('Text', ['Measure Value - ', num2str(Measure),'\n']); 

      if Success
          cprintf('green', '--- Success --- \n \n\n'); 
      else
          cprintf('red', 'Failure \n'); 
          Valid = false;
          cprintf('red', ['Failure of Test ',TestInformation{i}.name, ' \n']); 
          cprintf('red', ' --- Stopping Validation --- \n '); 
          return
      end
  end
  Valid = true;
  cprintf('green', 'Success of all Validation Tests \n'); 
  cprintf('green', ' --- Stopping Validation --- \n ');   
return
  
